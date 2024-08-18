//
//  main.cpp
//  Range Queries and Copies
//
//  Created by Yousef on 25.01.21.
//

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct Node
{
    ll value = 0;
    ll x, y;
    Node * left = nullptr;
    Node * right = nullptr;
    Node(ll v, ll x, ll y):
    value(v), x(x), y(y){
    }
};
vector<Node>t;

ll sum (ll a, ll b, ll k, Node * n, ll x, ll y)
{
    
    if((b < x || a > y) || n == NULL)
        return 0;
    if(a <= x && b >= y)
        return n->value;
    ll d = (x + y)/2;
    if(n == NULL)
        return 0;
    return sum(a, b, 2 * k, n->left, x, d) + sum(a, b, 2 * k + 1, n->right, d + 1, y);

}

Node * add (Node * current, ll p, ll value, ll a, ll b)
{
    if( p > b || p < a)
        return current;
    if(p == a && p== b)
    {
        Node *x = new Node(value,a,b);
        return x;
    }
    
    ll d = (a + b)/ 2;
    Node *x = new Node(0, a, b);
   
    if(current == nullptr)
    {
        x->left = add(nullptr, p, value, a, d);
        x->right = add(nullptr, p, value, d + 1, b);
    }
    else
    {
        x->left = add(current->left, p, value, a, d);
        x->right = add(current->right, p, value, d + 1, b);
    }
    if(x-> left != nullptr)
        x->value = x->left->value;
    
    if(x-> right != nullptr)
        x->value += x->right->value;
    
    return x;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, q, a, b, si, c, type, k, x;
    cin>>n>>q;
    
    for(int i = 0; i <= 18; i++)
        if((1<<i) >= n)
        {
            c = i;
            break;
        }
    si = (1<<c);
    cin>>a;
    
    t.push_back(Node(c,1,si));
    t.push_back(Node(c,1,si));
    t[1] = *add(nullptr, 1, a, 1, si);
    for (int i = 2; i <= n; i++)
    {
        cin>>a;
        
        t[1] = *add(&t[1], i, a, 1, si);
        
    }
    while(q--)
    {
        cin>>type;
        if(type == 3)
        {
            cin>>k;
            t.push_back(t[k]);
        }
        else if(type == 2)
        {
            cin>>k>>a>>b;
            cout<<sum(a, b, 1, &t[k], 1, si)<<"\n";
        }
        else
        {
            cin>>k>>a>>x;
            t[k] = *add(&t[k], a, x, 1, si);
            
        }
    }
    
    return 0;
}
