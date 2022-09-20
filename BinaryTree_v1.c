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

struct node* sortedArrayToBST(int arr[], int start, int end){

    if (start > end)
      return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    struct node *root = newNode(arr[mid]);
    root->left =  sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}


int main(){

    int n,m,i,j,c=0;
    int z = 0;
    struct node *root = NULL;
    int menu_option = 0, tr = 1, sort = 0, count = 0, count1 = 0, height = 0;
    int store[10001], store1[10001], arr_read[10001], balanced = 0;
    printf("Binary Tree (Mostly made for sorted and balanced types)");

    while (tr){
        int arr_write[count+count1], duplicate = 0; 
        printf("Main Menu\n");
        printf("1. Insert a node:\n");
        printf("2. Delete a node:\n");
        printf("3. Search for a node:\n");
        printf("4. In-order traversal.\n");
        printf("5. Pre-order traversal.\n");
        printf("6. Post-order traversal.\n");
        printf("7. Sort (Not possible to undo)\n");
        printf("8. Balance\n");
        printf("9. Input the nodes from a file\n");
        printf("0. Save the nodes to a file and quit\n");
        printf("Enter a choice: ");
        scanf("%d",&menu_option);

        switch(menu_option){

            case 1:
                if (sort == 1){
                int node;
                printf("Choose the number that you want to insert: ");
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
                int duplicate1 = 0;
                int node1;
                printf("Choose the number that you want to insert: ");
                scanf("%d",&node1);
                if (count1 !=0){
                for (int i=0; i<count1;i++){
                        if (store1[i] == node1){
                            duplicate1 = 1;
                            break;
                        }
                    }
                }      
                if (duplicate1 == 0 && count1 !=0){
                    store1[count1] = node1;
                    count1++;
                }
                if (count1 == 0){
                    store1[count1] = node1;
                    count1++;
                }
                }
                break;
            case 2:
                if (sort == 1){
                int del_node;
                printf("Choose the number you want to delete: ");
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
                    printf("Choose the number you want to delete: ");
                    scanf("%d",&del);
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
                if (sort == 1){
                int search;
                printf("Choose the number you seek: ");
                scanf("%d",&search);
                printf("It is at the position: ");
                search_node(root,search,z);
                printf("\n");
                } else if (sort == 0){
                int search1;
                printf("Choose the number you seek: ");
                scanf("%d",&search1);
                for(  i=0; i<count1; i++){
                    if (store1[i] == search1){
                        printf("It is at the position: %d\n",i+1);
                        break;
                    }
                } 
                }
                break;
            case 4:
                if (sort == 1){
                inorder(root);
                printf("\n");
                } else if (sort == 0){
                    for (i=0;i<count1;i++){
                    printf("%d ",store1[count1-1-i]);
                    }
                    printf("\n");
                }
                break;
            case 5:
                if (sort == 1){
                preorder(root);
                printf("\n");
                } else if (sort == 0){
                for (i=0;i<count1;i++){
                    printf("%d ",store1[i]);
                    }
                    printf("\n");
                }
                break;
            case 6:
                if (sort == 1){
                postorder(root);
                printf("\n");
                } else if (sort == 0){
                    for (i=0;i<count1;i++){
                    printf("%d ",store1[count1-1-i]);
                    }
                    printf("\n");
                }
                break;
            case 7:
                if (sort == 0){
                sort = 1;
                for (i=0; i<count1; i++){
                    root = insert(root, store1[i]);
                    store[i] = store1[i];
                    }
                }
                break;
            case 8:
                if (sort == 1){
                    if (checkHeightBalance(root,&height)){
                        printf("The tree is already balanced\n");
                    } else {
                        printf("The tree was balanced\n");
                        bubbleSort(store, count+count1);
                        root = sortedArrayToBST(store,0,count+count1-1);
                        preorder(root);
                        printf("\n");
                    }
            
                }
                break;
            case 9:
                FILE *fr;
                fr = fopen("BinaryTree","rb");
                if (fr == NULL){
                    printf("Error");
                    exit(1);
                }
                fread(arr_read, sizeof(int), sizeof(arr_read), fr);
                fclose(fr);
                for (i=0; i<arr_read[0]; i++){
                    store1[i] = arr_read[i+1];
                    count1++;
                }
                break;
            case 0:
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
                    arr_write[0] = count1;
                    for ( i=0; i<count1;i++){
                    arr_write[i+1] = store1[i];
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