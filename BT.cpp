    #include <iostream>
    #include <vector>
    using namespace std;
    class BT
    {
       private:
            struct node
            {
               node* left;
               node* right;
               int data;
            };
            node* root;
          public:
            BT()
            {
               root = NULL;
            }
            bool isEmpty() const { return root==NULL; }
            void displayinorder();
            void inorder(node*);
            void displaypreorder();
            void preorder(node*);
            void displaypostorder();
            void postorder(node*);
            void insert(int);
            void output(node*, vector<int>);
            void displayPath();
    };
    int main()
    {
        BT b;
        int ch,tmp,num;
        vector<int> myvector;
            cout << "Enter number of nodes: ";
            cin >> num;
            for(int i=0; i<num; i++)
            {
                cout <<endl;
                cout << "Enter node: ";
                cin >> tmp;
                b.insert(tmp);
            }
            choice:
            cout <<endl<<endl;
            cout << "Enter your choice: ";
            cout << "[1] In-order Traversal" <<endl;
            cout << "[2] Pre-order Traversal" <<endl;
            cout << "[3] Post-order Traversal" <<endl;
            cout << "[4] Output Paths from root to leaves";
            cout << "[5] Exit" <<endl;
            cin >> ch;
           switch(ch)
           {
               case 1: 
                   cout<<endl;
                   cout<<" In-Order Traversal "<<endl;
                   b.displayinorder();
                   break;
               case 2: 
                   cout<<endl;
                   cout<<" Pre-Order Traversal "<<endl;
                   b.displaypreorder();
                   break;
               case 3: 
                   cout<<endl;
                   cout<<" Post-Order Traversal "<<endl;
                   b.displaypostorder();
                   break;
               case 4:
                   cout<<endl;
                   cout<<" Output Paths from root to leaves: "<<endl;

                   b.displayPath();
               case 5: 
                   return 0;
                   break;
               default:
                   cout << "Invalid entry. Try Again";
                   goto choice;
                   break;                
           }
        return 0;
    }
    void BT::insert(int d)
    {
        node* t = new node;
        node* parent;
        t->data = d;
        t->left = NULL;
        t->right = NULL;
        parent = NULL;
        // is this a new tree?
        if(isEmpty()) root = t;
        else
        {
            //Note: ALL insertions are as leaf nodes
            node* curr;
            curr = root;
            // Find the Node's parent
            while(curr)
            {
                parent = curr;
                if(t->data > curr->data) curr = curr->right;
                else curr = curr->left;
            }
            if(t->data < parent->data)
               parent->left = t;
            else
               parent->right = t;
        }
    }
    void BT::displayinorder()
    {
      inorder(root);
    }
    void BT::inorder(node* p)
    {
        if(p != NULL)
        {
            if(p->left) inorder(p->left);
            cout<<" "<<p->data<<" ";
            if(p->right) inorder(p->right);
        }
        else return;
    }
    void BT::displaypreorder()
    {
        preorder(root);
    }
    void BT::preorder(node* p)
    {
        if(p != NULL)
        {
            cout<<" "<<p->data<<" ";
            if(p->left) preorder(p->left);
            if(p->right) preorder(p->right);
        }
        else return;
    }
    void BT::displaypostorder()
    {
        postorder(root);
    }
    void BT::postorder(node* p)
    {
        if(p != NULL)
        {
            if(p->left) postorder(p->left);
            if(p->right) postorder(p->right);
            cout<<" "<<p->data<<" ";
        }
        else return;
    }
    void BT::displayPath(){
        vector<int> myvector;
        output(root, myvector);
    }
    void BT::output(node* p, vector<int> myvector)
    {
        if(p == NULL) return;
        else{
            myvector.push_back(p->data);
            if(p->left==NULL && p->right==NULL){
                cout << "Output path: " <<endl;
                for(vector<int>::iterator itr =myvector.begin(); itr != myvector.end(); itr++){
                    cout << *itr << ",";
                }
                cout << endl;
            }
            else{
                output(p->left, myvector);
                output(p->right, myvector);
            }
        }
    }
