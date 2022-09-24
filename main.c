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

int search(int arr[], int strt, int end, int value){
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
}

struct node* buildTree(int in[], int pre[], int inStart, int inEnd){
    static int preIndex = 0;
 
    if (inStart > inEnd)
        return NULL;
 
    /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
    struct node* root = newNode(pre[preIndex++]);
 
    /* If this node has no children then return */
    if (inStart == inEnd)
        return root;
 
    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStart, inEnd, root->key);
 
    /* Using index in Inorder traversal, construct left and
     right subtress */
    root->left = buildTree(in, pre, inStart, inIndex - 1);
    root->right = buildTree(in, pre, inIndex + 1, inEnd);
 
    return root;
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

                // Checking for duplicates after that we can easily insert the number
                
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

                break;

            case 2:

                    //Deleting any number available in the tree

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
                int error = 0;
                for (i=0; i<count1; i++){
                    root = delete_bt(root, store1[i]);
                    store[i] = store1[i];
                    }
                while(root != NULL){
                    if (error == 10){
                        printf("There was an error with the inputed binary tree");
                        exit(1);
                    }
                    for (i=0; i<count1; i++){
                    root = delete_bt(root, store1[i]);
                    }
                    error++;

                }
                preorder(root);
                for (i=0; i<count1; i++){
                    root = insert(root, store1[i]);
                }
                printf("\nThe tree was sorted\n");
                printf("\n");
                preorder(root);
                printf("\n");
                break;

            case 8:

                    // We first sort the array with the binary tree's numbers 
                    // then we apply the balancing to the binary tree

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
                
                break;

            case 9:

                // Reading from the file the binary tree.
    
                if (sort == 0){
                FILE *fr;
                fr = fopen("BinaryTree.txt","r+");
                fscanf(fr,"%d ",&count1);
                if (fr == NULL || count1 == 0){
                    printf("Error");
                    exit(1);
                }

                int preListRead[count1], inListRead[count1];
                for (i=0;i<count1;i++){
                    fscanf(fr,"%d",&preListRead[i]);
                    store1[i] = preListRead[i];
                }
                for (i=0;i<count1;i++){
                    fscanf(fr,"%d",&inListRead[i]);
                }
                fclose(fr);
                printf("\nThe tree was inputed with success\n");
                printf("\n");    
                root = buildTree(inListRead, preListRead, 0, count1-1);
                preorder(root);
                printf("\n");
                }


                break;

            case 10:

                // Displaying the binary tree

                    printf("\n");
                    print_tree(root);
    
                break;

            case 0:

                // Storing the binary tree inside a file

                FILE *f;
                if (sort == 0){
                    int preList[count1+count], inList[count+count1];
                    printf("\n");
                    preorder_list(root,count1+count,z,preList);
                    z++;
                    inorder_list(root,count1+count,z,inList);
                    printf("\n");
                    
                    arr_write[0] = count1+count;
                    for (i=0; i<count1+count;i++){
                        arr_write[i+1] = preList[i];
                    }
                    for (i=count+count1; i<2*(count1+count);i++){
                        arr_write[i+1] = inList[i-count-count1];
                    }

                f = fopen("BinaryTree.txt","w+");
                if (f == NULL){
                    printf("Error");
                    exit(1);
                }
                for (i=0; i<2*(count+count1)+1; i++){
                    fprintf(f,"%d ",arr_write[i]);
                    if (i == 0 || i == count+count1)
                        fprintf(f,"\n");
                    
                }
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