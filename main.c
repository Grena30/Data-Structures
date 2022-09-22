#include<stdio.h>
#include<stdlib.h>
#define bool int

 
struct node{

    int key;
    int count;
    struct node *left, *right;
};
 

struct node *newNode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    temp->count = 1;
    return temp;
}
 

void preorder(struct node *root){
    if (root != NULL){
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right); 
    }
}


void inorder(struct node *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right); 
    }
}


void postorder(struct node *root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
        
        
    }
}


void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 

void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}


struct node* insert(struct node* node, int key){
    if (node == NULL) return newNode(key);
 
    if (key == node->key){
       (node->count)++;
        return node;
    }
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    return node;
}
 

struct node* minValueNode(struct node* node){
    struct node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}


struct node* deleteNode(struct node* root, int key){
    if (root == NULL) return root;
 
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    else{

        /* Duplicates taken into consideration

        if (root->count > 1){
           (root->count)--;
           return root;
        }
        */
 
        if (root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->count = temp->count;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;

}


bool checkHeightBalance(struct node *root, int *height){
  // Check for emptiness
  int leftHeight = 0, rightHeight = 0;
  int l = 0, r = 0;
  if (root == NULL){
    *height = 0;
    return 1;
  }

  l = checkHeightBalance(root->left, &leftHeight);
  r = checkHeightBalance(root->right, &rightHeight);

  *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

  if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2))
    return 0;

  else
    return l && r;
}


void search_node(struct node* root, int n, int z){
    
    static int count0[10001] = {0};
    if (root == NULL)
        return;

    count0[z]++;
    if (root->key == n)
        printf("%d ", count0[z]);

    search_node(root->left, n,z);
    search_node(root->right, n,z);    
}


struct node* balanceBST(int arr[], int start, int end){

    if (start > end)
      return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    struct node *root = newNode(arr[mid]);
    root->left =  balanceBST(arr, start, mid-1);
    root->right = balanceBST(arr, mid+1, end);
 
    return root;
}


void tabs(int num){
    for (int i=0; i<num; i++){
        printf("\t");
    }
}


void print_tree_rec(struct node* root, int level){
    if (root == NULL){
        tabs(level);
        printf("-empty-\n");
        return;
    }
    tabs(level);
    printf("value = %d\n",root->key);
    tabs(level);

    printf("left\n");
    print_tree_rec(root->left, level + 1);
    tabs(level);

    printf("right\n");
    print_tree_rec(root->right, level + 1);
    tabs(level);
    printf("done\n");
}

void print_tree(struct node* root){
    print_tree_rec(root,0);
}

struct node* insert_bt(struct node* node, int key, char or){
    if (node == NULL) return newNode(key);
 
    if (key == node->key){
       (node->count)++;
        return node;
    }
    if (or == 'l')
        node->left  = insert_bt(node->left, key, or);
    else
        node->right = insert_bt(node->right, key, or);
 
    return node;
}

struct node* delete_bt(struct node* root, int key){
    if (root == NULL) return root;
 
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
 
    if (key == root->key){

        /* Duplicates taken into consideration

        if (root->count > 1){
           (root->count)--;
           return root;
        }
        */
 
        if (root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->count = temp->count;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;

}

void preorder_list(struct node* root, int n, int z, int arr[]){
    
    static int count1[10001] = {0};
    if (root == NULL)
        return;

    if (count1[z] <= n){

        arr[count1[z]] = (root->key);
        count1[z]++;

        preorder_list(root->left, n,z, arr);
        preorder_list(root->right, n,z, arr);

    } else {
        return;
    }    
}

void inorder_list(struct node* root, int n, int z, int arr[]){
    
    static int count2[10001] = {0};
    if (root == NULL)
        return;

    if (count2[z] <= n){

        inorder_list(root->left, n,z, arr);
        arr[count2[z]] = (root->key);
        count2[z]++;

        inorder_list(root->right, n,z, arr);

    } else {
        return;
    }    
}


int main(){

    int n,m,i,j,c=0;
    int z = 0;
    struct node *root = NULL;
    int tr = 1, sort = 0, count = 0, count1 = 0, height = 0;
    int store[10001], store1[10001], arr_read[10001], balanced = 0;
    int menu_option = 0;
    char orient[10001];

    while (tr){
        int arr_write[count+count1], duplicate = 0; 
        printf("------------------------------------------\n");
        printf("Main Menu\n");
        printf("1. Insert a node:\n");
        printf("2. Delete a node:\n");
        printf("3. Search for a node:\n");
        printf("4. In-order traversal.\n");
        printf("5. Pre-order traversal.\n");
        printf("6. Post-order traversal.\n");
        printf("7. Sort\n");
        printf("8. Balance\n");
        printf("9. Input from file\n");
        printf("10. Display the tree\n");
        printf("0. Save and exit\n");
        printf("------------------------------------------\n");
        printf("Enter a choice: ");
        scanf("%d",&menu_option);

        switch(menu_option){

            case 1:

                // Checking for sort and duplicates after that we can easily insert the number
                
                if (sort == 1){
                int node;
                printf("\nChoose the number that you want to insert: ");
                scanf("%d",&node);
                for (i = 0; i < count+count1; i++){
                    if(store[i] == node)
                        duplicate = 1;
                }
                if (duplicate == 0){
                store[count+count1] = node;
                root = insert(root,node);
                count++;
                }

                } else if (sort == 0){
                int duplicate1 = 0, node1;
                char or;
                printf("\nChoose number that you want to insert and 'l' or 'r': ");
                scanf("%d %c",&node1, &or);
                for ( i=0; i<count1;i++){
                        if (store1[i] == node1)
                            duplicate1 = 1;
                }  
                if (duplicate1 == 0){
                    root = insert_bt(root, node1, or);
                    orient[count1] = or;
                    store1[count1] = node1;
                    count1++;
                }
                /*if (count1 == 0){
                    root = insert_bt(root, node1, or);
                    store1[count1] = node1;
                    count1++;
                }*/
                }
                break;

            case 2:

                // Checking for sort and then we can delete any number available in the tree

                if (sort == 1){
                int del_node;
                printf("\nChoose the number you want to delete: ");
                scanf("%d",&del_node);
                root = deleteNode(root,del_node);
                for(int i=0; i<count+count1; i++){
                    if (store[i] == del_node){
                        store[i] = store[i+1];
                        for (int j=i+1; j<count+count1; j++){
                            store[j] = store[j+1];
                        }
                        count--;
                        break;
                    } else {
                        continue;
                    }
                    }
                } else if (sort == 0){
                    int del;
                    printf("\nChoose the number you want to delete: ");
                    scanf("%d",&del);
                    root = delete_bt(root, del);
                    for(int i=0; i<count1; i++){
                    if (store1[i] == del){
                        store1[i] = store1[i+1];
                        for (int j=i+1; j<count1; j++){
                            store1[j] = store1[j+1];
                        }
                        count1--;

                        break;
                    } else {
                        continue;
                    }
                    }
                }
                break;

            case 3:

                // Checking for sort and then we look for the specified number

                int search;
                printf("\nChoose the number you seek: ");
                scanf("%d",&search);
                printf("\nIt is at the position: ");
                search_node(root,search,z);
                printf("\n");
                break;

            case 4:

                // In-order traversal
                
                printf("\n");
                inorder(root);
                printf("\n");
                break;

            case 5:

                // Pre-order traversal
               
                printf("\n");
                preorder(root);
                printf("\n");
                break;

            case 6:
                
                // Post-order traversal
                
                printf("\n");
                postorder(root);
                printf("\n");
                break;

            case 7:

                // Sorting the binary tree

                for (i=0; i<count1; i++){
                    root = deleteNode(root, store1[i]);
                    store[i] = store1[i];
                    }
                for (i=0; i<count1; i++){
                    root = insert(root, store1[i]);
                }
                printf("\n");
                preorder(root);
                printf("\n");
                break;

            case 8:

                /* Firstly we check the sort and then for the separate cases
                    in the first we verify the balance if it is false then
                    we balance the sorted binary tree, in the second we
                    first sort the binary tree then we apply the balancing
                */

                if (sort == 1){
                    if (checkHeightBalance(root,&height)){
                        printf("\nThe tree is already balanced\n");
                    } else {
                        printf("\nThe tree was balanced\n");
                        bubbleSort(store, count+count1);
                        root = balanceBST(store,0,count+count1-1);
                        preorder(root);
                        printf("\n");
                    }
                } else if (sort == 0){
                    if (checkHeightBalance(root,&height)){
                        printf("\nThe tree is already balanced\n");
                    } else {
                        printf("\nThe tree was balanced\n");
                        bubbleSort(store1, count+count1);
                        root = balanceBST(store1,0,count+count1-1);
                        printf("\n");
                        preorder(root);
                        printf("\n");
                    }
                }
                break;

            case 9:

                /* Reading from the file the binary tree.
                    The tree is not sorted nor balanced
                    even if it was saved while being both
                */

                FILE *fr;
                fr = fopen("BinaryTree","rb");
                if (fr == NULL){
                    printf("Error");
                    exit(1);
                }
                fread(arr_read, sizeof(int), sizeof(arr_read), fr);
                fclose(fr);
                count1 = arr_read[0];
                for (i=0; i<arr_read[0]; i++){
                    store1[i] = arr_read[i+1];
                }
                break;

            case 10:

                // Checking for sort then displaying the binary tree
                    printf("\n");
                    print_tree(root);
    
                break;

            case 0:

                // Storing the binary tree inside a file

                FILE *f;
                if (sort == 1){
                    arr_write[0] = count+count1;
                for ( i=0; i<count+count1;i++){
                    arr_write[i+1] = store[i];
                }
                f = fopen("BinaryTree","wb");
                if (f == NULL){
                    printf("Error");
                    exit(1);
                }
                fwrite(arr_write, sizeof(int), sizeof(arr_write), f);
                fclose(f);
                exit(0);
                } else if (sort == 0){
                    int preList[count1+count], inList[count+count1];
                    printf("\n");
                    preorder_list(root,count1+count,z,preList);
                    z++;
                    inorder_list(root,count1+count,z,inList);
                    printf("\n");
                    for (i=0; i<count+count1; i++){
                        printf("%d ",preList[i]);
                    }
                    printf("\n");
                    for (i=0; i<count+count1; i++){
                        printf("%d ",inList[i]);
                    }

                    arr_write[0] = count1+count;
                    for (i=0; i<count1+count;i++){
                    arr_write[i+1] = preList[i];
                    }
                    for (i=count+count1; i<2*(count1+count);i++){
                    arr_write[i+1] = inList[i-count-count1];
                    }
                    printf("\n");
                    for (i=0; i<2*(count1+count);i++){
                        printf("%d ",arr_write[i]);
                    }
                f = fopen("BinaryTree","wb");
                if (f == NULL){
                    printf("Error");
                    exit(1);
                }
                fwrite(arr_write, sizeof(int), sizeof(arr_write), f);
                fclose(f);
                exit(0);
                }
                break;

            default:
                printf("Invalid input\n");
            break;
        }

        z++;  

    }

return 0;
}
