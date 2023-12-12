#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#include <iostream>
#include <limits.h>


#define MAX_VERTICES 50


typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

typedef struct GraphNode
//���� ����Ʈ�� ��� ������ ����ü ������ �ڷ������� �����մϴ�.
{
    int vertex;
    //������ ��Ÿ���� ������ �ʵ带 ���������� �����մϴ�.
    struct GraphNode* link;
    //���� ���� ������ �����ϴ� ��ũ�ʵ��Դϴ�.
}GraphNode;

struct Edge {
    int destination;
    struct Edge* next;
};

// ������ ��Ÿ���� ����ü
struct Vertex {
    struct Edge* head;
};

// �׷����� ��Ÿ���� ����ü
struct Graph {
    int numVertices;
    struct Vertex* array;
};

// �׷��� �ʱ�ȭ �Լ�
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    
    // �� ������ ���� ����Ʈ�� ����
    graph->array = (struct Vertex*)malloc(vertices * sizeof(struct Vertex));
    for (int i = 0; i < vertices; ++i) {
        graph->array[i].head = NULL;
    }
    
    return graph;
}




//-------------------------------------------------
typedef struct NodeStruct
{
    int value;
    struct NodeStruct* leftChild;
    struct NodeStruct* rightChild;
}Node;

Node* root = NULL;

Node* BST_insert(Node* root, int value)
{
    if (root == NULL)
    {
        root = (Node*)malloc(sizeof(Node));
        root->leftChild = root->rightChild = NULL;
        root->value = value;
        return root;
    }
    else
    {
        if (root->value > value)
            root->leftChild = BST_insert(root->leftChild, value);
        else
            root->rightChild = BST_insert(root->rightChild, value);
    }
    return root;
}
Node* findMinNode(Node* root)
{
    Node* tmp = root;
    while (tmp->leftChild != NULL)
        tmp = tmp->leftChild;
    return tmp;
}

Node* BST_search(Node* root, int value)
{
    if (root == NULL)
        return NULL;

    if (root->value == value)
        return root;
    else if (root->value > value)
        return BST_search(root->leftChild, value);
    else
        return BST_search(root->rightChild, value);
}

//---------------------------

//--------------------

void textcolor(int colorNum) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void BST_print(Node* root)
{
    if (root == NULL)
        return;

    printf("%d ", root->value);
    BST_print(root->leftChild);
    BST_print(root->rightChild);
}

void BST_print(Node* root, int space)
{
    int i;

    // �⺻ ���� ������ 10���� ����
    int count = 10;

    // �� Ʈ����� ��ȯ
    if (root == NULL)
        return;

    // ������ �ڽ� ��带 ���� ��� (�����ʺ��� �Ʒ���)
    BST_print(root->rightChild, space + count);
    Sleep(2000);

    printf(" ");
        for (i = count; i < space; i++)
            printf("");
    printf("%d", root->value);

        // ���� ���� �ڽ� ��带 ���
        BST_print(root->leftChild, space + count);
        Sleep(2000);
}

//---------




//-------------------------------------------

void init(GraphType* g) {
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++)
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
    printf("�׷��� �ʱ�ȭ �Ϸ�\n");
}

void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "overflow");
        return;
    }
    g->n++;
    printf("���� %d ���� �Ϸ�\n", v);
    Sleep(3000);
}

void insert_edge(GraphType* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "vertex key error");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
    printf("���� (%d, %d) ���� �Ϸ�\n", start, end);
    Sleep(3000);
}

void print_adj_mat(GraphType* g) {
    printf("���� ��� ��� ����\n");
    Sleep(3000);
    for (int i = 0; i < g->n; i++){
            for (int j = 0; j < g->n; j++) {
                printf("%2d", g->adj_mat[i][j]);
            }
            printf("\n");
            Sleep(3000);
        }
    printf("���� ��� ��� �Ϸ�\n");
}

//------------------------------------------

void addEdge(struct Graph* graph, int src, int dest) {
    // src���� dest�� ���� ������ �߰�
    struct Edge* edge = (struct Edge*)malloc(sizeof(struct Edge));
    edge->destination = dest;
    edge->next = graph->array[src].head;
    graph->array[src].head = edge;

    // dest���� src�� ���� ������ �߰� (������ �׷���)
    edge = (struct Edge*)malloc(sizeof(struct Edge));
    edge->destination = src;
    edge->next = graph->array[dest].head;
    graph->array[dest].head = edge;
}

// �׷��� ��� �Լ�
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        struct Edge* current = graph->array[i].head;
        printf("���� %d�� ����� ����: ", i);
        while (current != NULL) {
            printf("%d ", current->destination);
            Sleep(2000);
            current = current->next;
        }
        printf("\n");
    }
}

//----------------------------------------





   

 
//-----------------



//------------------

void init();
void titleDraw();
void gotoxy(int, int);
void menuDraw();
void printArray(int arr[], int size);  // printArray �Լ� ����
void selectionSort(int arr[], int size);  // selectionSort �Լ� ����
void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void input();


void plot_array(int arr[], int size, const char* title) {
    printf("%s: [", title);
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[size - 1]);
}

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
void shellSort(int arr[], int size);
void heapify(int arr[], int size, int i);
void heapSort(int arr[], int size);
void radixSort(int arr[], int size);
void countingSortForRadix(int arr[], int size, int exp);

int* createArray(int size) {
    return new int[size];
}

void deleteArray(int* arr) {
    delete[] arr;
}

int main() {
	system("cls");
    init();
    titleDraw();
    menuDraw();
    input();
    return 0;
}

void input() {
    int select;
    gotoxy(109, 32);
    scanf("%d", &select);
    switch (select) {
    case 1:
        system("cls");
        gotoxy(90, 10);
        printf("1. ���� ����");
        gotoxy(90, 14);
        printf("2. ���� ����");
        gotoxy(90, 18);
        printf("3. ���� ����");
        gotoxy(90, 22);
        printf("4. ���� ����");
        gotoxy(90, 26);
        printf("5. �� ����");
        gotoxy(90, 30);
        printf("6. �� ����");
        gotoxy(90, 34);
        printf("7. ��� ����");
        gotoxy(90, 38);
        printf("8. ��� ����");
        gotoxy(90, 42);
        printf("0. �ڷ� ����");
        gotoxy(90, 46);
        printf("��ȣ�� �Է����ּ���: ");
        scanf("%d", &select);

        if (select == 1) {
            system("cls");\
            
             gotoxy(80, 10);
            printf("���� ������ ����?");
            Sleep(2000);
            gotoxy(80, 12);
            printf("��Ʈ���� ���� ���� �κ��� ��ô�.");
            Sleep(2000);
            gotoxy(80, 14);
            printf("1. ���ڸ� ������ �˰����̴�.");
            Sleep(2000);
            gotoxy(80, 16);
            printf("2. �ش� ������ ���Ҹ� ���� ��ġ�� �̹� �������ְ�, � ���Ҹ� ������ �����ϴ� �˰����̴�.");
            Sleep(2000);
            gotoxy(80, 18);
            printf("�׷� ������ ��� �Ǵ°���?");
            Sleep(2000);
            gotoxy(80, 20);
            printf("1. �־��� �迭 �߿��� �ּڰ��� ã�´�.");
            Sleep(2000);
            gotoxy(80, 22);
            printf("2. �� ���� �� �տ� ��ġ�� ���� ��ü�Ѵ�.");
            Sleep(2000);
            gotoxy(80, 24);
            printf("3. �� ó�� ��ġ�� �� ������ ����Ʈ�� ���� ������� ��ü�Ѵ�.");
            Sleep(2000);
            
            gotoxy(80, 26);
            printf("4. �ϳ��� ���Ҹ� ���� ������ ���� ������ �ݺ��Ѵ�.");
            Sleep(2000);
            gotoxy(80, 28);
            printf("�ð� ���⵵�� ?");
            Sleep(2000);
            gotoxy(80, 30);
            printf("n**2");
            Sleep(2000);
            gotoxy(80, 32);
            printf("�׷� �ѹ� �迭�� �Է��غ���!");
            Sleep(2000);
            
            
            system("cls");
            gotoxy(90, 10);


            int size;
            gotoxy(80, 3);
            printf("�迭�� ũ�⸦ �Է��ϼ���: ");
            scanf("%d", &size);

            int* arr = (int*)malloc(size * sizeof(int));

            printf("�迭�� ��Ҹ� �Է��ϼ���:\n");
            for (int i = 0; i < size; i++) {
                printf("arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }

            system("cls");
            gotoxy(80, 10);
            printf("���� ���� ���� �� �迭:\n");
            gotoxy(80,20);
            printArray(arr, size);
            Sleep(1000);

            selectionSort(arr, size);



            free(arr);

            printf("5�� �� ����ȭ������ ���ư��ϴ�.");
            Sleep(5000);
            main();

        }

        else if (select == 2) {
        	
        	  system("cls");\
            
             gotoxy(80, 10);
            printf("���� ������ ����?");
            Sleep(2000);
            gotoxy(80, 12);
            printf("��Ʈ���� ���� ���� �κ��� ��ô�.");
            Sleep(2000);
            gotoxy(80, 14);
            printf("1. ���� ������ �� ���Ҹ� �˻��Ͽ� �����ϴ� �˰����̴�.");
            Sleep(2000);
            gotoxy(80, 16);
            printf("2. ���� ���İ� �⺻ ������ �����ϴ�..");
            Sleep(2000);
            gotoxy(80, 18);
            printf("�׷� ������ ��� �Ǵ°���?");
            Sleep(2000);
            gotoxy(60, 20);
            printf("1ȸ���� ù�� ° ���ҿ� �ι��� ���Ҹ�, �� ��° ���ҿ� �� ���� ���Ҹ� ... �̷� ������ (������ - 1)��° ���ҿ� ������ ���Ҹ� ���Ͽ� ���ǿ� ���� ������ ���� ��ȯ�Ѵ�.");
            gotoxy(80, 22);
            printf("�� �� 1ȸ���� �����ϰ� ���� ���� ū ���Ұ� �� �ڷ� �̵��ϹǷ� �� ���� �ִ� ���Ҵ� ���Ŀ��� ���ܵȴ�.");
            Sleep(10000);
            gotoxy(80, 24);
            printf("�ð� ���⵵�� ?");
            Sleep(2000);
            gotoxy(80, 26);
            printf("n**2");
            Sleep(2000);
            gotoxy(80, 28);
            printf("�׷� �ѹ� �迭�� �Է��غ���!");
            Sleep(2000);
            
            
            system("cls");
            gotoxy(90, 14);

            int size;
            gotoxy(80, 3);
            printf("�迭�� ũ�⸦ �Է��ϼ���: ");
            scanf("%d", &size);

            int* arr = (int*)malloc(size * sizeof(int));

            printf("�迭�� ��Ҹ� �Է��ϼ���:\n");
            for (int i = 0; i < size; i++) {
                printf("arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }

            system("cls");
            gotoxy(80, 10);
            printf("���� ���� ���� �� �迭:\n");
            gotoxy(80,20);
            printArray(arr, size);
            Sleep(1000);

            bubbleSort(arr, size);

            free(arr);

            printf("��� �� ����ȭ������ ���ư��ϴ�.");
            Sleep(5000);
            main();
        }

        else if (select == 3) {
        	  system("cls");
            
             gotoxy(50, 10);
            printf("���� ������ ����?");
            Sleep(2000);
            gotoxy(50, 12);
            printf("��Ʈ���� ���� ���� �κ��� ��ô�.");
            Sleep(2000);
            gotoxy(50, 14);
            printf("1. �ڷ� �迭�� ��� ��Ҹ� �տ������� ���ʴ�� �̹� ���ĵ� �κа� ���Ͽ� �ڽ��� ��ġ�� ã�� �����Ͽ� ������ �ϼ��ϴ� �˰���");
            Sleep(2000);
            gotoxy(50, 16);
            printf("�׷� ������ ��� �Ǵ°���?");
            Sleep(2000);
            gotoxy(50, 18);
            printf(" ���� ������ �� ��° �ڷ���� �����Ͽ� �� ��(����)�� �ڷ��� ���Ͽ� ������ ��ġ�� ������ �� �ڷḦ �ڷ� �ű�� ������ �ڸ��� �ڷḦ �����Ͽ� �����ϴ� �˰����̴�");
            gotoxy(50, 20);
            printf("��, �� ��° �ڷ�� ù ��° �ڷ�, �� ��° �ڷ�� �� ��°�� ù ��° �ڷ�, �� ��° �ڷ�� �� ��°, �� ��°, ù ��° �ڷ�� ���� �� �ڷᰡ ���Ե� ��ġ�� ã�´�. ");
            gotoxy(50,22);
            printf("�ڷᰡ ���Ե� ��ġ�� ã�Ҵٸ� �� ��ġ�� �ڷḦ �����ϱ� ���� �ڷḦ �� ĭ�� �ڷ� �̵�");
            Sleep(8000);
            gotoxy(50, 24);
            printf("�ð� ���⵵�� ?");
            Sleep(2000);
            gotoxy(50, 26);
            printf("n");
            Sleep(2000);
            gotoxy(50, 28);
            printf("�׷� �ѹ� �迭�� �Է��غ���!");
            Sleep(2000);
            system("cls");
            gotoxy(90, 18);


            int size;
            gotoxy(80, 3);
            printf("�迭�� ũ�⸦ �Է��ϼ���: ");
            scanf("%d", &size);

            int* arr = (int*)malloc(size * sizeof(int));

            printf("�迭�� ��Ҹ� �Է��ϼ���:\n");
            for (int i = 0; i < size; i++) {
                printf("arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }

            system("cls");
            gotoxy(80, 10);
            printf("���� ���� ���� �� �迭:\n");
            gotoxy(80,20);
            printArray(arr, size);
            Sleep(1000);

            insertionSort(arr, size);

            free(arr);
            main();
        }

        else if (select == 4) {
        	system("cls");
        	    gotoxy(50, 10);
            printf("���� ������ ����?");
            Sleep(2000);
            gotoxy(50, 12);
            printf("��Ʈ���� ���� ���� �κ��� ��ô�.");
            Sleep(2000);
            gotoxy(50, 14);
            printf("1. �� �� ���̸�(John von Neumann)���̶�� ����� ������ ���");
            Sleep(2000);
            gotoxy(50, 16);
            printf("2. ���� ���� ����� �̿�");
            Sleep(2000);
            gotoxy(50, 18);
            printf(" ������ ?");
            gotoxy(50, 20);
            printf("1. ����Ʈ�� ���̰� 0 �Ǵ� 1�̸� �̹� ���ĵ� ������ ����. �׷��� ���� ��쿡�� ���ĵ��� ���� ����Ʈ�� �������� �߶� ����� ũ���� �� �κ� ����Ʈ�� ������");
            gotoxy(50,22);
            printf("2.�� �κ� ����Ʈ�� ��������� �պ� ������ �̿��� �����Ѵ�");
            gotoxy(50,24) ;
            printf("3. �� �κ� ����Ʈ�� �ٽ� �ϳ��� ���ĵ� ����Ʈ�� �պ��Ѵ�.");
            Sleep(8000);
            gotoxy(50, 26);
            printf("�ð� ���⵵�� ?");
            Sleep(2000);
            gotoxy(50, 28);
            printf("nlogn");
            Sleep(2000);
            gotoxy(50, 30);
            printf("�׷� �ѹ� �迭�� �Է��غ���!");
            Sleep(2000);
            system("cls");
            
            system("cls");
            gotoxy(90, 22);

            int size;
            gotoxy(80, 3);
            printf("�迭�� ũ�⸦ �Է��ϼ���: ");
            scanf("%d", &size);

            int* arr = (int*)malloc(size * sizeof(int));

            printf("�迭�� ��Ҹ� �Է��ϼ���:\n");
            for (int i = 0; i < size; i++) {
                printf("arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }

            system("cls");
            gotoxy(80, 10);
            printf("���� ���� ���� �� �迭:\n");
            gotoxy(80,20);
            printArray(arr, size);
            Sleep(1000);

            mergeSort(arr, 0, size - 1);

            free(arr);

            printf("5�� �� ����ȭ������ ���ư��ϴ�.");
            Sleep(5000);
            main();
        }

        else if (select == 5) {
            system("cls");
            gotoxy(90, 26);


            int size;
            gotoxy(80, 3);
            printf("�迭�� ũ�⸦ �Է��ϼ���: ");
            scanf("%d", &size);

            int* arr = (int*)malloc(size * sizeof(int));

            printf("�迭�� ��Ҹ� �Է��ϼ���:\n");
            for (int i = 0; i < size; i++) {
                printf("arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }

            system("cls");
            gotoxy(80, 10);
            printf("�� ���� ���� �� �迭:\n");
            gotoxy(80,20);
            printArray(arr, size);
            Sleep(1000);
            shellSort(arr, size);

            free(arr);

            printf("5�� �� ����ȭ������ ���ư��ϴ�.");
            Sleep(5000);
            main();
        }

        else if (select == 6) {
            system("cls");
            gotoxy(90, 30);

            int size;
            gotoxy(80, 3);
            printf("�迭�� ũ�⸦ �Է��ϼ���: ");
            scanf("%d", &size);

            int* arr = (int*)malloc(size * sizeof(int));

            printf("�迭�� ��Ҹ� �Է��ϼ���:\n");
            for (int i = 0; i < size; i++) {
                printf("arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }

            system("cls");
            gotoxy(80, 10);
            printf("�� ���� ���� �� �迭:\n");
            gotoxy(80,20);
            printArray(arr, size);
            Sleep(1000);

            heapSort(arr, size);

            free(arr);

            printf("5�� �� ����ȭ������ ���ư��ϴ�.");
            Sleep(5000);
            main();
        }

        else if (select == 7) {

        }

        else if (select == 8) {

        }



        else if (select == 0) {
            system("cls");
            main();
        }
        break;


    case 2:
        system("cls");
        gotoxy(90, 18);
        printf("1. ���� �˻� Ʈ��");
        gotoxy(90, 22); 
        printf("2. ���� �� Ʈ��");
        gotoxy(90, 26);
        printf("3. B - Ʈ��");
        gotoxy(90, 30);
        printf("4. ������ �˻� Ʈ��");
        gotoxy(90, 34);
        printf("0. �ڷ� ����");
        gotoxy(90, 38);
        printf("��ȣ�� �Է����ּ���: ");
        scanf("%d", &select);

        if (select == 0) {
            system("cls");
            main();
        }

        else if (select == 1) {
            
            system("cls");

            gotoxy(30, 30);
            printf("22");
            gotoxy(26, 32);
            printf("15");
            gotoxy(34, 32);
            printf("45");
            gotoxy(24, 34);
            printf("7");
            gotoxy(28, 34);
            printf("18");
            gotoxy(31, 34);
            printf("36");
            gotoxy(36, 34);
            printf("60");
           
            root = BST_insert(root, 22);
            root = BST_insert(root, 45);
            root = BST_insert(root, 36);
            root = BST_insert(root, 60);
            
            gotoxy(60, 26);
            printf("���� Ž�� Ʈ���� ����?");
            Sleep(2000);

            gotoxy(60, 28);
            printf("�θ����� ���ʳ��� �۾ƾߵǰ� ������ ���� Ŀ�ߵ˴ϴ�. (������ Ž��Ʈ���� ��迭�� Ʈ�� �Դϴ�. )");
            Sleep(2000);

            gotoxy(60, 30);
            printf("�׷� �� ���� Ž��Ʈ���� ū �������� ã�Ƽ� ��迭 �����ٷ�? ");
            Sleep(2000);
            gotoxy(60,32);
            printf("�� �˰ڽ��ϴ�.");
            BST_print(root, 0);
            printf("\n");
          
 
            gotoxy(60, 34);
            printf("22�� ã�ҽ��ϴ�! 5�� �� ���θ޴��� ���ư��ϴ�. ");
            Sleep(5000);

            main();
       
        }

        else if (select == 2) {

            system("cls");
            gotoxy(80, 10);
            printf("���� �� Ʈ��������?");
            Sleep(3000);
            gotoxy(80, 12);
            printf("��Ʈ���� ���� �� Ʈ���κ��� ��ô�.");
            Sleep(3000);
            gotoxy(80, 14);
            printf("1. ��� ���� ������ Ȥ�� �������̴�.");
            Sleep(3000);
            gotoxy(80, 16);
            printf("2. ��Ʈ ���� �������̴�..");
            Sleep(3000);
            gotoxy(80, 18);
            printf("3. ��� ���� ���(NIL)���� �������̴�. (NIL : null leaf, �ڷḦ ���� �ʰ� Ʈ���� ���� ��Ÿ���� ���");
            Sleep(3000);
            gotoxy(80, 20);
            printf("4.������ ����� �ڽ��� �������̴�. == No Dubble Red");
            Sleep(3000);
            gotoxy(80, 22);
            printf("5.��� ���� ��忡�� Black Depth�� ����.");
            Sleep(3000);
            gotoxy(80, 24);
            printf("��... �� �𸣰����� ���� �ѹ� �׷��� �غ��߰ڴ�.");
            Sleep(5000);
           


            system("cls");
            gotoxy(30, 30);
            printf("8");
            Sleep(2000);
            gotoxy(27, 31);
            textcolor(12);
            printf("7");
            Sleep(2000);
            gotoxy(33, 31);
            printf("9");
            Sleep(2000);
            gotoxy(25, 32);
            printf("3");
            Sleep(2000);
            textcolor(7);
            gotoxy(100, 33);
            printf("Recoloring");
            Sleep(2000);
            gotoxy(27, 31);
            printf("7");
            Sleep(2000);
            gotoxy(33, 31);
            printf("9");
            Sleep(2000);
            textcolor(12);
            gotoxy(27, 33);
            printf("6");
            Sleep(2000);
            textcolor(7);
            gotoxy(100, 33);
            printf("Restructuring");
            Sleep(2000);
            textcolor(7);
            gotoxy(27, 31);
            printf("6");
            Sleep(2000);
            textcolor(12);
            gotoxy(29, 32);
            printf("7");
            Sleep(2000);
            textcolor(7);
            gotoxy(27, 33);
            printf(" ");
            gotoxy(100, 33);
            printf("�����Ʈ���� �������ϴ�. 10���� �������� ���ư��ϴ�.");
            Sleep(10000);
            
            main();
        }




    case 3:
        system("cls");
        gotoxy(90, 10);
        printf("1. ���� ����� �̿�");
        gotoxy(90, 14);
        printf("2. ���� ����Ʈ�� �̿�");
        gotoxy(90, 18);
        printf("3. ���� �˰���");
        gotoxy(90, 22);
        printf("4. ũ�罺Į �˰���");
        gotoxy(90, 26);
        printf("5. ��������");
        gotoxy(90, 30);
        printf("6. ���ͽ�Ʈ�� �˰���");
        gotoxy(90, 34);
        printf("7. ����-���� �˰���");
        gotoxy(90, 38);
        printf("8. ������ ���");
        gotoxy(90, 42);
        printf("0. �ڷ� ����");
        gotoxy(90, 46);
        printf("��ȣ�� �Է����ּ���: ");
        scanf("%d", &select);

        if (select == 0) {
            system("cls");
            main();
        }
        if (select == 1) {
            system("cls");
            GraphType* g;
            g = (GraphType*)malloc(sizeof(GraphType));
            init(g);
            for (int i = 0; i < 4; i++)
                insert_vertex(g, i);
            insert_edge(g, 0, 1);
            insert_edge(g, 0, 2);
            insert_edge(g, 0, 3);
            insert_edge(g, 1, 2);
            insert_edge(g, 2, 3);
            print_adj_mat(g);
            free(g);
            Sleep(3000);
            main();
        }
        else if (select == 2) {
            system("cls");
            int vertices = 5; // ������ ����
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
    Sleep(3000);
    system("cls");
    main();
        }
        
        else if (select == 3) {
        	system("cls");
        	
           gotoxy(50, 50);
           printf("1");
           gotoxy(40,50);
           printf("2");
           gotoxy(60,60);
           printf("3");
           gotoxy(60,50);
           printf("4");
           gotoxy(50,60);
           printf("5");
           gotoxy(40,60);
           printf("6");
           
           
           Sleep(3000);  
		   textcolor(12);
		   gotoxy(50, 50);
		   printf("1");
		   
		   Sleep(3000);
		    textcolor(7);
           gotoxy(100, 50);
		   printf("1�� 2 ������ �Ÿ� 3");
		   
		   Sleep(3000);
		   gotoxy(100, 50);
		   printf("1�� 4 ������ �Ÿ� 5");
		   
		   Sleep(3000);
		   textcolor(7);
		   gotoxy(100, 50);
		   printf("     2�� �Ѿ      ");
		   
		   Sleep(3000);
		   textcolor(12);
		   gotoxy(40,50);
           printf("2");
           
             Sleep(3000);
             textcolor(7);
		   gotoxy(100, 50);
		   printf("2�� 6 ������ �Ÿ� 1");
		   
		     Sleep(3000);
		   gotoxy(100, 50);
		   printf("2�� 5 ������ �Ÿ� 3");
		   
		    Sleep(3000);
		   textcolor(7);
		   gotoxy(100, 50);
		    printf("     6�� �Ѿ      ");
		   
		     Sleep(3000);
		     textcolor(12);
		       gotoxy(40,60);
           printf("6");
		   textcolor(7);
		   gotoxy(100, 50);
		     printf("     5�� �Ѿ(2)     ");
		   
		    Sleep(3000);
		    textcolor(12);
		    gotoxy(50,60);
           printf("5");
		   gotoxy(100, 50);
		   textcolor(7);
		   printf("5�� 3 ������ �Ÿ� 2");
		   
		     Sleep(3000);
		   gotoxy(100, 50);
		   printf("5�� 4 ������ �Ÿ� 1");
		   
		       Sleep(3000);
		   textcolor(7);
		   gotoxy(100, 50);
		   printf("         4�� �Ѿ       ");
		   Sleep(3000);
		    textcolor(12);
		     gotoxy(60,50);
           printf("4");
           
             Sleep(3000);
              textcolor(7);
		   gotoxy(100, 50);
		    printf("         3�� �Ѿ(1)        ");
		    Sleep(3000);
		    textcolor(12);
		      gotoxy(40,60);
           printf("6");
           
           Sleep(3000);
           
		   gotoxy(100, 50);
           textcolor(12);
		   printf("   �ּ� ����ġ =    8  (5���� �����մϴ�) ");
		
		   Sleep(5000);
           
        
		    textcolor(7);
		   main();
        }

    case 4:
        system("cls");
        gotoxy(90, 18);
        printf("1. ���� ���� Ʈ��");
        gotoxy(90, 22);
        printf("2. ��Ʈ��ŷ");
        gotoxy(90, 26);
        printf("3. �����б�");
        gotoxy(90, 30);
        printf("4. A* �˰���(TSP)");
        gotoxy(90, 34);
        printf("0. �ڷΰ���");
        gotoxy(90, 38);
        printf("��ȣ�� �Է����ּ���: ");
        scanf("%d", &select);

        if (select == 0) {
            system("cls");
            main();
        }
    

    case 0:
        system("cls");
        exit(0);

        break;
    default:
        printf("��ȿ���� ���� �����Դϴ�. �ùٸ� �ɼ��� �������ּ���.\n");
        system("cls");
        main();
    }
}

void init() {
}

void titleDraw() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                                          ##########            #########              #########                #########\n");
    printf("                                                          #        #                    #                      #                   # #   \n");
    printf("                                                          #        #                    #              #########                  #   #   \n");
    printf("                                                          #        #                    #              #                         #     #   \n");
    printf("                                                          ##########                    #              #########                #       #   \n");
}

void menuDraw() {
    gotoxy(95, 20);
    printf("1. ����");
    gotoxy(93, 22);
    printf("2. �˻� Ʈ��");
    gotoxy(94, 24);
    printf("3. �׷��� ");
    gotoxy(90, 26);
    printf("4. ���� ���� Ʈ�� ");
    gotoxy(93, 29);
    printf("0. �����ϱ�");
    gotoxy(88, 32);
    printf("���ڸ� �Է����ּ���: ");
    gotoxy(70, 45);
    printf("�� ��ȿ���� ���� ��ȣ�� ���� �� ���θ޴��� �ӹ����ϴ�.");
}

void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        system("cls");
        gotoxy(80, 10);
        printf("���� ���� ���� ��...\n");
         gotoxy(10, 20);
        printf("���� �迭 ����: ");
        gotoxy(80,20);
        printArray(arr, size);
        Sleep(3000);
    }

    system("cls");
    gotoxy(80, 10);
    printf("���� ���� �Ϸ� �� �迭:\n");
    	 gotoxy(80,20);
    printArray(arr, size);
    printf("5���� �����ϴ�. ");
    Sleep(5000);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
	
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                system("cls");
                gotoxy(80, 10);
                printf("���� ���� ���� ��...\n");
                 gotoxy(10, 20);
                printf("���� �迭 ����: ");
                 gotoxy(80, 20);
                printArray(arr, size);
                Sleep(2000);
            }
        }
    }

    system("cls");
    gotoxy(80, 10);
    printf("���� ���� �Ϸ� �� �迭:\n");
     gotoxy(80,20);
    printArray(arr, size);
    Sleep(5000);
}

void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;

            system("cls");
            gotoxy(80, 10);
            printf("���� ���� ���� ��...\n");
			gotoxy(10, 20);
            printf("���� �迭 ����: ");
             gotoxy(80, 20);
            printArray(arr, size);
            Sleep(2000);
        }
        arr[j + 1] = key;
    }

    system("cls");
    gotoxy(80, 10);
    printf("���� ���� �Ϸ� �� �迭:\n");
     gotoxy(80,20);
    printArray(arr, size);
    Sleep(5000);
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // �ӽ� �迭 ����
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // �ӽ� �迭�� ������ ����
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // �� ���� �ӽ� �迭�� ����
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;

        system("cls");
        gotoxy(80, 10);
        printf("���� ���� ���� ��...\n");
         gotoxy(80,20);
        printf("���� �迭 ����: ");
        printArray(arr, right - left + 1);
        Sleep(2000);
    }

    // ���� ��ҵ� ����
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;

        system("cls");
        gotoxy(80, 10);
        printf("���� ���� ���� ��...\n");
         gotoxy(80,20);
        printf("���� �迭 ����: ");
        printArray(arr, right - left + 1);
        Sleep(2000);
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;

        system("cls");
        gotoxy(80, 10);
        printf("���� ���� ���� ��...\n");
         gotoxy(80,20);
        printf("���� �迭 ����: ");
        printArray(arr, right - left + 1);
        Sleep(2000);
    }

    // �ӽ� �迭 �޸� ����
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // ���� �κ� �迭 ����
        mergeSort(arr, left, mid);

        // ������ �κ� �迭 ����
        mergeSort(arr, mid + 1, right);

        // ���ĵ� �� �迭�� ����
        merge(arr, left, mid, right);
    }
}

void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];

                system("cls");
                gotoxy(80, 10);
                printf("�� ���� ���� ��...\n");
                 gotoxy(80,20);
                printf("���� �迭 ����: ");
                printArray(arr, size);
                Sleep(1000);
            }
            arr[j] = temp;
        }
    }

    system("cls");
    gotoxy(80, 10);
    printf("�� ���� �Ϸ� �� �迭:\n");
     gotoxy(80,20);
    printArray(arr, size);
    Sleep(5000);
}

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // ���� �ڽ��� ��Ʈ���� ū ���
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // ������ �ڽ��� ��Ʈ���� ū ���
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // ���� ū ���� ���� ���� ��ȯ
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        system("cls");
        gotoxy(80, 10);
        printf("�� ���� ���� ��...\n");
         gotoxy(80,20);
        printf("���� �迭 ����: ");
        printArray(arr, size);
        Sleep(1000);

        // ��ȯ �� ��������� heapify ȣ��
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    // �� ����
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // ������ �ϳ��� ��Ҹ� ���� ����
    for (int i = size - 1; i >= 0; i--) {
        // ��Ʈ�� ������ ��� ��ȯ
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        system("cls");
        gotoxy(80, 10);
        printf("�� ���� ���� ��...\n");
         gotoxy(80,20);
        printf("���� �迭 ����: ");
        printArray(arr, size);
        Sleep(1000);

        // ��ȯ �� ���� �籸��
        heapify(arr, i, 0);
    }

    system("cls");
    gotoxy(80, 10);
    printf("�� ���� �Ϸ� �� �迭:\n");
     gotoxy(80,20);
    printArray(arr, size);
    Sleep(5000);
}



//----------------------------------------------------------------------------------------------------------------------//

