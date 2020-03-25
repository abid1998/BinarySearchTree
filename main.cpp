#include <iostream>
#include <queue>
using namespace std;

//tree_node Template
template <class T>
class tree_node {
public:
	T data;
	tree_node *left, *right, *parent;

	tree_node() {
		left = right = parent = NULL;
	};

	tree_node(T &dataue) {
		data = dataue;
	};

	~tree_node() {
	};
	
	void operator= (const tree_node<T> &other) {
		data = other.data;
	};

	bool operator< (T &other) {
		return (data < other);
	};
};

//binary_search_tree Template
template <class T>
class binary_search_tree {
public:
	binary_search_tree() {
		root = NULL;
	};

	~binary_search_tree() {
		destroy(root);
	};

	virtual void insert(T &dataue) {
		insert(root,NULL,dataue);
	};

	virtual tree_node<T>* search(T &dataue) {
		return search(root,dataue);
	};

	virtual bool remove(T &dataue) {
		return remove(root,dataue);
	};

	virtual bool operator< (binary_search_tree<T> &other) {
		return (root->data < other.first()->data);
	};

	void operator= (binary_search_tree<T> &other) {
		equal(root,other.first());
	};

	tree_node<T>*& first() {
		return root;
	};

    void print_reverse_inorder() {
        print_reverse_inorder(this->root);
        cout<<endl;
    }

    void print_inorder() {
        print_inorder(this->root);
        cout<<endl;
    }

    void print_postorder() {
        print_postorder(this->root);
        cout<<endl;
    }

    void print_preorder() {
        print_preorder(this->root);
        cout<<endl;
    }

    void level_order_travesal() {
 
        level_order_travesal(this->root);
    }

    int depth() {
        return depth(this->root);
    }

    T lowest_common_ancestor(T &p, T &q) {
        return lowest_common_ancestor(this->root, p, q)->data;
    }

    void level_wise_largest() {
 
        level_wise_largest(this->root);
    }

    void right_side_view() {
        right_side_view(this->root);
    }

    bool is_symmetric() {
        return is_symmetric(this->root, this->root);
    }

    void bottom_left_value() {
        bottom_left_value(this->root);
    }

    bool is_subtree(tree_node<T>* s) {
        return is_subtree(s, this->tree);
    }

private:

	tree_node<T> *root;

    bool is_subtree_helper(tree_node<T>* s, tree_node<T>* t)
    {
        if(s == NULL && t == NULL)
            return true;
        if(s == NULL || t == NULL)
            return false;
        return s->data == t->data && is_subtree_helper(s->left, t->left) && is_subtree_helper(s->right, t->right);
    }
    
    bool is_subtree(tree_node<T>* s, tree_node<T>* t) {
        if(s == NULL && t == NULL)
            return true;
        if(s == NULL)
            return false;
        if(is_subtree_helper(s, t)) return true;
        return is_subtree(s->left, t) || is_subtree(s->right, t);
        
    }

    void bottom_left_value(tree_node<T>* root) {
        queue<tree_node<T>*> q;
        q.push(root);
        T lt;
        while(!q.empty())
        {
            int size = q.size();
            vector<T> tv;
            for(int i=0; i<size; i++)
            {
                tree_node<T>* temp = q.front();
                tv.push_back(temp->data);
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            lt = tv[0];
        }
        cout << lt <<endl;
    }

    bool is_symmetric(tree_node<T>*root1, tree_node<T> *root2) {
        if(root1 == NULL && root2 == NULL)
            return true;
        if(root1 == NULL || root2 == NULL)
            return false;
        return root1->data == root2->data && is_symmetric(root1->right, root2->left) && is_symmetric(root1->left, root2->right);
    }

    void right_side_view(tree_node<T>* root) {
        queue<tree_node<T>* > q;
        if(root == NULL)
            return;
        
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                tree_node<T> *temp = q.front();
                q.pop();
                if(i == size-1) {
                    cout<<temp->data<<endl;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }

    void level_order_travesal(tree_node<T>* root) {
        
        if(root == NULL)
            return;
        queue <tree_node<T>*> q;
        int level = 0;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            cout<<"Level "<<level<<": ";
            for(int i=0; i<size; i++)
            {
                tree_node<T> *temp = q.front();
                cout<<temp->data<<" ";
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            cout<<endl;
            level++;
        }
    }

    void level_wise_largest(tree_node<T>* root) {
        
        if(root == NULL)
            return;
        queue <tree_node<T>*> q;
        int level = 0;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            T max = q.front()->data;
            for(int i=0; i<size; i++)
            {
                tree_node<T> *temp = q.front();
                if(max < temp->data)
                {
                    max = temp->data;
                }
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            cout<<"Maximum value at level "<<level+1<<" = "<<max<<endl;
            level++;
        }
    }
    
    tree_node<T>* lowest_common_ancestor(tree_node<T>* root, T &p, T &q) {
        if(root->data <= p && root->data >= q)
            return root;
        else if(root->data >= p && root->data <= q)
            return root;
        else if(root->data > p && root->data > q)
            return lowest_common_ancestor(root->left, p, q);
        else if(root->data < p && root->data < q)
            return lowest_common_ancestor(root->right, p, q);
        return root;
    }

    int depth(tree_node<T>* node) {
        return node == NULL ? 0 : max(depth(node->left)+1, depth(node->right)+1);
    }

	void equal(tree_node<T>*& node, tree_node<T>* dataue) {
		if(dataue != NULL) {
			node = new tree_node<T>();
			*node = *dataue;
			if(dataue->left != NULL)
				equal(node->left, dataue->left);
			if(dataue->right != NULL)
				equal(node->right, dataue->right);
		}
	}

    void print_reverse_inorder(tree_node<T>* node){
		if(node == NULL)
            return;
        print_inorder(node->left);
        cout<<node->data<<" ";
        print_inorder(node->right);
	};

    void print_inorder(tree_node<T>* node){
		if(node == NULL)
            return;
        print_inorder(node->left);
        cout<<node->data<<" ";
        print_inorder(node->right);
	};

    void print_preorder(tree_node<T>* node){
		if(node == NULL)
            return;
        
        cout<<node->data<<" ";
        print_preorder(node->left);
        print_preorder(node->right);
	};

    void print_postorder(tree_node<T>* node){
		if(node == NULL)
            return;
        print_postorder(node->left);
        print_postorder(node->right);
        cout<<node->data<<" ";
        
	};

	void destroy(tree_node<T>* dataue) {
		if(dataue != NULL) {
			destroy(dataue->left);
			destroy(dataue->right);
			delete dataue;
		}
	};

	void insert(tree_node<T> *&node, tree_node<T> *parent, T &dataue) {
		if(node == NULL) {
			node = new tree_node<T>();
			*node = dataue;
			node->parent = parent;
		} else if(dataue < node->data) {
			insert(node->left,node,dataue);
		} else
			insert(node->right,node,dataue);
	};

	void insert(tree_node<T> *&node, tree_node<T> *parent, binary_search_tree<T> &tree) {
		tree_node<T> *dataue = tree.first();
		if(node == NULL) {
			node = new tree_node<T>();
			*node = *dataue;
			node->parent = parent;
		} else if(dataue->data < node->data) {
			insert(node->left,tree);
		} else
			insert(node->right,tree);
	};

	tree_node<T>* search(tree_node<T> *node, T &dataue) {
		if(node == NULL) 
			return NULL;
		else if(dataue == node->data)
			return node;
		else if(dataue < node->data)
			return search(node->left,dataue);
		else
			return search(node->right,dataue);
	};

	bool remove(tree_node<T> *node, T &dataue) {
		
		tree_node<T> *tmp = search(root,dataue);
		if(tmp == NULL)
			return false;
		tree_node<T> *parent = tmp->parent;
		
		bool iamleft = false;
		if(parent->left == tmp)
			iamleft = true;
		if(tmp->left != NULL && tmp->right != NULL) {
			if(parent->left == NULL || parent->right == NULL) {
				parent->left = tmp->left;
				parent->right = tmp->right;
			} else {
				if(iamleft)
					parent->left = tmp->left;
				else
					parent->right = tmp->left;
				T data = tmp->right->data;
				delete tmp;
				insert(root,NULL,data);
			}
		} else if(tmp->left != NULL) {
			if(iamleft)
				parent->left = tmp->left;
			else
				parent->right = tmp->left;
		} else if(tmp->right != NULL ) {
			if(iamleft)
				parent->left = tmp->right;
			else
				parent->right = tmp->right;
		} else {
			if(iamleft)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		return true;
	};
};

int main()
{
    binary_search_tree<int> t;
    int a = 10;
    cout << t.depth() << endl;
    t.insert(a);
    cout << t.depth() << endl;
    a = 102;
    cout << t.depth() << endl;
    t.insert(a);
    a = 100;
    t.insert(a);
    a = 1;
    t.insert(a);
    cout << t.depth() << endl;
    t.print_inorder();
    t.print_postorder();
    t.print_preorder();
    int x = 1, y = 100;
    cout<<t.lowest_common_ancestor(x, y);
    t.level_wise_largest();
    t.right_side_view();
    cout<<t.is_symmetric()<<endl;
    t.bottom_left_value();
    t.level_order_travesal();
    return 0;
}