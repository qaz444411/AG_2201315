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
//인접 리스트의 노드 구조를 구조체 형태의 자료형으로 선언합니다.
{
    int vertex;
    //정점을 나타내는 데이터 필드를 정수형으로 선언합니다.
    struct GraphNode* link;
    //다음 인접 정점을 연결하는 링크필드입니다.
}GraphNode;

struct Edge {
    int destination;
    struct Edge* next;
};

// 정점을 나타내는 구조체
struct Vertex {
    struct Edge* head;
};

// 그래프를 나타내는 구조체
struct Graph {
    int numVertices;
    struct Vertex* array;
};

// 그래프 초기화 함수
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    
    // 각 정점에 대한 리스트를 생성
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

    // 기본 공백 간격은 10으로 설정
    int count = 10;

    // 빈 트리라면 반환
    if (root == NULL)
        return;

    // 오른쪽 자식 노드를 먼저 출력 (오른쪽부터 아래로)
    BST_print(root->rightChild, space + count);
    Sleep(2000);

    printf(" ");
        for (i = count; i < space; i++)
            printf("");
    printf("%d", root->value);

        // 이제 왼쪽 자식 노드를 출력
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
    printf("그래프 초기화 완료\n");
}

void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "overflow");
        return;
    }
    g->n++;
    printf("정점 %d 삽입 완료\n", v);
    Sleep(3000);
}

void insert_edge(GraphType* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "vertex key error");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
    printf("간선 (%d, %d) 삽입 완료\n", start, end);
    Sleep(3000);
}

void print_adj_mat(GraphType* g) {
    printf("인접 행렬 출력 시작\n");
    Sleep(3000);
    for (int i = 0; i < g->n; i++){
            for (int j = 0; j < g->n; j++) {
                printf("%2d", g->adj_mat[i][j]);
            }
            printf("\n");
            Sleep(3000);
        }
    printf("인접 행렬 출력 완료\n");
}

//------------------------------------------

void addEdge(struct Graph* graph, int src, int dest) {
    // src에서 dest로 가는 간선을 추가
    struct Edge* edge = (struct Edge*)malloc(sizeof(struct Edge));
    edge->destination = dest;
    edge->next = graph->array[src].head;
    graph->array[src].head = edge;

    // dest에서 src로 가는 간선도 추가 (무방향 그래프)
    edge = (struct Edge*)malloc(sizeof(struct Edge));
    edge->destination = src;
    edge->next = graph->array[dest].head;
    graph->array[dest].head = edge;
}

// 그래프 출력 함수
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        struct Edge* current = graph->array[i].head;
        printf("정점 %d과 연결된 정점: ", i);
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
void printArray(int arr[], int size);  // printArray 함수 선언
void selectionSort(int arr[], int size);  // selectionSort 함수 선언
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
        printf("1. 선택 정렬");
        gotoxy(90, 14);
        printf("2. 버블 정렬");
        gotoxy(90, 18);
        printf("3. 삽입 정렬");
        gotoxy(90, 22);
        printf("4. 병합 정렬");
        gotoxy(90, 26);
        printf("5. 쉘 정렬");
        gotoxy(90, 30);
        printf("6. 힙 정렬");
        gotoxy(90, 34);
        printf("7. 기수 정렬");
        gotoxy(90, 38);
        printf("8. 계수 정렬");
        gotoxy(90, 42);
        printf("0. 뒤로 가기");
        gotoxy(90, 46);
        printf("번호를 입력해주세요: ");
        scanf("%d", &select);

        if (select == 1) {
            system("cls");\
            
             gotoxy(80, 10);
            printf("선택 정렬이 뭐야?");
            Sleep(2000);
            gotoxy(80, 12);
            printf("노트에서 선택 정렬 부분을 펴봤다.");
            Sleep(2000);
            gotoxy(80, 14);
            printf("1. 제자리 정렬의 알고리즘이다.");
            Sleep(2000);
            gotoxy(80, 16);
            printf("2. 해당 순서에 원소를 넣을 위치는 이미 정해져있고, 어떤 원소를 넣을지 선택하는 알고리즘이다.");
            Sleep(2000);
            gotoxy(80, 18);
            printf("그럼 과정이 어떻게 되는거지?");
            Sleep(2000);
            gotoxy(80, 20);
            printf("1. 주어진 배열 중에서 최솟값을 찾는다.");
            Sleep(2000);
            gotoxy(80, 22);
            printf("2. 그 값을 맨 앞에 위치한 값과 교체한다.");
            Sleep(2000);
            gotoxy(80, 24);
            printf("3. 맨 처음 위치를 뺀 나머지 리스트를 같은 방법으로 교체한다.");
            Sleep(2000);
            
            gotoxy(80, 26);
            printf("4. 하나의 원소만 남을 때까지 위의 과정을 반복한다.");
            Sleep(2000);
            gotoxy(80, 28);
            printf("시간 복잡도는 ?");
            Sleep(2000);
            gotoxy(80, 30);
            printf("n**2");
            Sleep(2000);
            gotoxy(80, 32);
            printf("그럼 한번 배열을 입력해보자!");
            Sleep(2000);
            
            
            system("cls");
            gotoxy(90, 10);


            int size;
            gotoxy(80, 3);
            printf("배열의 크기를 입력하세요: ");
            scanf("%d", &size);

            int* arr = (int*)malloc(size * sizeof(int));

            printf("배열의 요소를 입력하세요:\n");
            for (int i = 0; i < size; i++) {
                printf("arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }

            system("cls");
            gotoxy(80, 10);
            printf("선택 정렬 시작 전 배열:\n");
            gotoxy(80,20);
            printArray(arr, size);
            Sleep(1000);

            selectionSort(arr, size);



            free(arr);

            printf("5초 후 메인화면으로 돌아갑니다.");
            Sleep(5000);
            main();

        }

        else if (select == 2) {
        	
        	  system("cls");\
            
             gotoxy(80, 10);
            printf("버블 정렬이 뭐야?");
            Sleep(2000);
            gotoxy(80, 12);
            printf("노트에서 버블 정렬 부분을 펴봤다.");
            Sleep(2000);
            gotoxy(80, 14);
            printf("1. 서로 인접한 두 원소를 검사하여 정렬하는 알고리즘이다.");
            Sleep(2000);
            gotoxy(80, 16);
            printf("2. 선택 정렬과 기본 개념이 유사하다..");
            Sleep(2000);
            gotoxy(80, 18);
            printf("그럼 과정이 어떻게 되는거지?");
            Sleep(2000);
            gotoxy(60, 20);
            printf("1회전에 첫번 째 원소와 두번쨰 원소를, 두 번째 원소와 세 번쨰 원소를 ... 이런 식으로 (마지막 - 1)번째 원소와 마지막 원소를 비교하여 조건에 맞지 않으면 서로 교환한다.");
            gotoxy(80, 22);
            printf("이 때 1회전을 수행하고 나면 가장 큰 원소가 맨 뒤로 이동하므로 맨 끝에 있는 원소는 정렬에서 제외된다.");
            Sleep(10000);
            gotoxy(80, 24);
            printf("시간 복잡도는 ?");
            Sleep(2000);
            gotoxy(80, 26);
            printf("n**2");
            Sleep(2000);
            gotoxy(80, 28);
            printf("그럼 한번 배열을 입력해보자!");
            Sleep(2000);
            
            
            system("cls");
            gotoxy(90, 14);

            int size;
            gotoxy(80, 3);
            printf("배열의 크기를 입력하세요: ");
            scanf("%d", &size);

            int* arr = (int*)malloc(size * sizeof(int));

            printf("배열의 요소를 입력하세요:\n");
            for (int i = 0; i < size; i++) {
                printf("arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }

            system("cls");
            gotoxy(80, 10);
            printf("버블 정렬 시작 전 배열:\n");
            gotoxy(80,20);
            printArray(arr, size);
            Sleep(1000);

            bubbleSort(arr, size);

            free(arr);

            printf("잠시 후 메인화면으로 돌아갑니다.");
            Sleep(5000);
            main();
        }

        else if (select == 3) {
        	  system("cls");
            
             gotoxy(50, 10);
            printf("삽입 정렬이 뭐야?");
            Sleep(2000);
            gotoxy(50, 12);
            printf("노트에서 삽입 정렬 부분을 펴봤다.");
            Sleep(2000);
            gotoxy(50, 14);
            printf("1. 자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 부분과 비교하여 자신의 위치를 찾아 삽입하여 정렬을 완성하는 알고리즘");
            Sleep(2000);
            gotoxy(50, 16);
            printf("그럼 과정이 어떻게 되는거지?");
            Sleep(2000);
            gotoxy(50, 18);
            printf(" 삽입 정렬은 두 번째 자료부터 시작하여 그 앞(왼쪽)의 자료들과 비교하여 삽입할 위치를 지정한 후 자료를 뒤로 옮기고 지정한 자리에 자료를 삽입하여 정렬하는 알고리즘이다");
            gotoxy(50, 20);
            printf("즉, 두 번째 자료는 첫 번째 자료, 세 번째 자료는 두 번째와 첫 번째 자료, 네 번째 자료는 세 번째, 두 번째, 첫 번째 자료와 비교한 후 자료가 삽입될 위치를 찾는다. ");
            gotoxy(50,22);
            printf("자료가 삽입될 위치를 찾았다면 그 위치에 자료를 삽입하기 위해 자료를 한 칸씩 뒤로 이동");
            Sleep(8000);
            gotoxy(50, 24);
            printf("시간 복잡도는 ?");
            Sleep(2000);
            gotoxy(50, 26);
            printf("n");
            Sleep(2000);
            gotoxy(50, 28);
            printf("그럼 한번 배열을 입력해보자!");
            Sleep(2000);
            system("cls");
            gotoxy(90, 18);


            int size;
            gotoxy(80, 3);
            printf("배열의 크기를 입력하세요: ");
            scanf("%d", &size);

            int* arr = (int*)malloc(size * sizeof(int));

            printf("배열의 요소를 입력하세요:\n");
            for (int i = 0; i < size; i++) {
                printf("arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }

            system("cls");
            gotoxy(80, 10);
            printf("삽입 정렬 시작 전 배열:\n");
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
            printf("병합 정렬이 뭐야?");
            Sleep(2000);
            gotoxy(50, 12);
            printf("노트에서 병합 정렬 부분을 펴봤다.");
            Sleep(2000);
            gotoxy(50, 14);
            printf("1. 존 폰 노이만(John von Neumann)’이라는 사람이 제안한 방법");
            Sleep(2000);
            gotoxy(50, 16);
            printf("2. 분할 정복 방법을 이용");
            Sleep(2000);
            gotoxy(50, 18);
            printf(" 과정은 ?");
            gotoxy(50, 20);
            printf("1. 리스트의 길이가 0 또는 1이면 이미 정렬된 것으로 본다. 그렇지 않은 경우에는 정렬되지 않은 리스트를 절반으로 잘라 비슷한 크기의 두 부분 리스트로 나눈다");
            gotoxy(50,22);
            printf("2.각 부분 리스트를 재귀적으로 합병 정렬을 이용해 정렬한다");
            gotoxy(50,24) ;
            printf("3. 두 부분 리스트를 다시 하나의 정렬된 리스트로 합병한다.");
            Sleep(8000);
            gotoxy(50, 26);
            printf("시간 복잡도는 ?");
            Sleep(2000);
            gotoxy(50, 28);
            printf("nlogn");
            Sleep(2000);
            gotoxy(50, 30);
            printf("그럼 한번 배열을 입력해보자!");
            Sleep(2000);
            system("cls");
            
            system("cls");
            gotoxy(90, 22);

            int size;
            gotoxy(80, 3);
            printf("배열의 크기를 입력하세요: ");
            scanf("%d", &size);

            int* arr = (int*)malloc(size * sizeof(int));

            printf("배열의 요소를 입력하세요:\n");
            for (int i = 0; i < size; i++) {
                printf("arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }

            system("cls");
            gotoxy(80, 10);
            printf("병합 정렬 시작 전 배열:\n");
            gotoxy(80,20);
            printArray(arr, size);
            Sleep(1000);

            mergeSort(arr, 0, size - 1);

            free(arr);

            printf("5초 후 메인화면으로 돌아갑니다.");
            Sleep(5000);
            main();
        }

        else if (select == 5) {
            system("cls");
            gotoxy(90, 26);


            int size;
            gotoxy(80, 3);
            printf("배열의 크기를 입력하세요: ");
            scanf("%d", &size);

            int* arr = (int*)malloc(size * sizeof(int));

            printf("배열의 요소를 입력하세요:\n");
            for (int i = 0; i < size; i++) {
                printf("arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }

            system("cls");
            gotoxy(80, 10);
            printf("쉘 정렬 시작 전 배열:\n");
            gotoxy(80,20);
            printArray(arr, size);
            Sleep(1000);
            shellSort(arr, size);

            free(arr);

            printf("5초 후 메인화면으로 돌아갑니다.");
            Sleep(5000);
            main();
        }

        else if (select == 6) {
            system("cls");
            gotoxy(90, 30);

            int size;
            gotoxy(80, 3);
            printf("배열의 크기를 입력하세요: ");
            scanf("%d", &size);

            int* arr = (int*)malloc(size * sizeof(int));

            printf("배열의 요소를 입력하세요:\n");
            for (int i = 0; i < size; i++) {
                printf("arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }

            system("cls");
            gotoxy(80, 10);
            printf("힙 정렬 시작 전 배열:\n");
            gotoxy(80,20);
            printArray(arr, size);
            Sleep(1000);

            heapSort(arr, size);

            free(arr);

            printf("5초 후 메인화면으로 돌아갑니다.");
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
        printf("1. 이진 검색 트리");
        gotoxy(90, 22); 
        printf("2. 레드 블랙 트리");
        gotoxy(90, 26);
        printf("3. B - 트리");
        gotoxy(90, 30);
        printf("4. 다차원 검색 트리");
        gotoxy(90, 34);
        printf("0. 뒤로 가기");
        gotoxy(90, 38);
        printf("번호를 입력해주세요: ");
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
            printf("이진 탐색 트리가 뭐야?");
            Sleep(2000);

            gotoxy(60, 28);
            printf("부모노드의 왼쪽노드는 작아야되고 오른쪽 노드는 커야됩니다. (왼쪽은 탐색트리로 재배열된 트리 입니다. )");
            Sleep(2000);

            gotoxy(60, 30);
            printf("그럼 이 이진 탐색트리를 큰 순서먼저 찾아서 재배열 시켜줄래? ");
            Sleep(2000);
            gotoxy(60,32);
            printf("넵 알겠습니다.");
            BST_print(root, 0);
            printf("\n");
          
 
            gotoxy(60, 34);
            printf("22을 찾았습니다! 5초 뒤 메인메뉴로 돌아갑니다. ");
            Sleep(5000);

            main();
       
        }

        else if (select == 2) {

            system("cls");
            gotoxy(80, 10);
            printf("레드 블랙 트리가뭐야?");
            Sleep(3000);
            gotoxy(80, 12);
            printf("노트에서 레드 블랙 트리부분을 펴봤다.");
            Sleep(3000);
            gotoxy(80, 14);
            printf("1. 모든 노드는 빨간색 혹은 검은색이다.");
            Sleep(3000);
            gotoxy(80, 16);
            printf("2. 루트 노드는 검은색이다..");
            Sleep(3000);
            gotoxy(80, 18);
            printf("3. 모든 리프 노드(NIL)들은 검은색이다. (NIL : null leaf, 자료를 갖지 않고 트리의 끝을 나타내는 노드");
            Sleep(3000);
            gotoxy(80, 20);
            printf("4.빨간색 노드의 자식은 검은색이다. == No Dubble Red");
            Sleep(3000);
            gotoxy(80, 22);
            printf("5.모든 리프 노드에서 Black Depth는 같다.");
            Sleep(3000);
            gotoxy(80, 24);
            printf("음... 잘 모르겠으니 내가 한번 그려서 해봐야겠다.");
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
            printf("레드블랙트리가 끝났습니다. 10초후 메인으로 돌아갑니다.");
            Sleep(10000);
            
            main();
        }




    case 3:
        system("cls");
        gotoxy(90, 10);
        printf("1. 인접 행렬을 이용");
        gotoxy(90, 14);
        printf("2. 인접 리스트를 이용");
        gotoxy(90, 18);
        printf("3. 프림 알고리즘");
        gotoxy(90, 22);
        printf("4. 크루스칼 알고리즘");
        gotoxy(90, 26);
        printf("5. 위상정렬");
        gotoxy(90, 30);
        printf("6. 다익스트라 알고리즘");
        gotoxy(90, 34);
        printf("7. 벨만-포드 알고리즘");
        gotoxy(90, 38);
        printf("8. 강연결 요소");
        gotoxy(90, 42);
        printf("0. 뒤로 가기");
        gotoxy(90, 46);
        printf("번호를 입력해주세요: ");
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
            int vertices = 5; // 정점의 개수
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
		   printf("1과 2 사이의 거리 3");
		   
		   Sleep(3000);
		   gotoxy(100, 50);
		   printf("1과 4 사이의 거리 5");
		   
		   Sleep(3000);
		   textcolor(7);
		   gotoxy(100, 50);
		   printf("     2로 넘어감      ");
		   
		   Sleep(3000);
		   textcolor(12);
		   gotoxy(40,50);
           printf("2");
           
             Sleep(3000);
             textcolor(7);
		   gotoxy(100, 50);
		   printf("2과 6 사이의 거리 1");
		   
		     Sleep(3000);
		   gotoxy(100, 50);
		   printf("2과 5 사이의 거리 3");
		   
		    Sleep(3000);
		   textcolor(7);
		   gotoxy(100, 50);
		    printf("     6로 넘어감      ");
		   
		     Sleep(3000);
		     textcolor(12);
		       gotoxy(40,60);
           printf("6");
		   textcolor(7);
		   gotoxy(100, 50);
		     printf("     5로 넘어감(2)     ");
		   
		    Sleep(3000);
		    textcolor(12);
		    gotoxy(50,60);
           printf("5");
		   gotoxy(100, 50);
		   textcolor(7);
		   printf("5과 3 사이의 거리 2");
		   
		     Sleep(3000);
		   gotoxy(100, 50);
		   printf("5과 4 사이의 거리 1");
		   
		       Sleep(3000);
		   textcolor(7);
		   gotoxy(100, 50);
		   printf("         4로 넘어감       ");
		   Sleep(3000);
		    textcolor(12);
		     gotoxy(60,50);
           printf("4");
           
             Sleep(3000);
              textcolor(7);
		   gotoxy(100, 50);
		    printf("         3로 넘어감(1)        ");
		    Sleep(3000);
		    textcolor(12);
		      gotoxy(40,60);
           printf("6");
           
           Sleep(3000);
           
		   gotoxy(100, 50);
           textcolor(12);
		   printf("   최소 가중치 =    8  (5초후 종료합니다) ");
		
		   Sleep(5000);
           
        
		    textcolor(7);
		   main();
        }

    case 4:
        system("cls");
        gotoxy(90, 18);
        printf("1. 상태 공간 트리");
        gotoxy(90, 22);
        printf("2. 백트래킹");
        gotoxy(90, 26);
        printf("3. 한정분기");
        gotoxy(90, 30);
        printf("4. A* 알고리즘(TSP)");
        gotoxy(90, 34);
        printf("0. 뒤로가기");
        gotoxy(90, 38);
        printf("번호를 입력해주세요: ");
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
        printf("유효하지 않은 선택입니다. 올바른 옵션을 선택해주세요.\n");
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
    printf("1. 정렬");
    gotoxy(93, 22);
    printf("2. 검색 트리");
    gotoxy(94, 24);
    printf("3. 그래프 ");
    gotoxy(90, 26);
    printf("4. 상태 공간 트리 ");
    gotoxy(93, 29);
    printf("0. 종료하기");
    gotoxy(88, 32);
    printf("숫자를 입력해주세요: ");
    gotoxy(70, 45);
    printf("※ 유효하지 않은 번호를 누를 시 메인메뉴에 머무릅니다.");
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
        printf("선택 정렬 진행 중...\n");
         gotoxy(10, 20);
        printf("현재 배열 상태: ");
        gotoxy(80,20);
        printArray(arr, size);
        Sleep(3000);
    }

    system("cls");
    gotoxy(80, 10);
    printf("선택 정렬 완료 후 배열:\n");
    	 gotoxy(80,20);
    printArray(arr, size);
    printf("5초후 꺼집니다. ");
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
                printf("버블 정렬 진행 중...\n");
                 gotoxy(10, 20);
                printf("현재 배열 상태: ");
                 gotoxy(80, 20);
                printArray(arr, size);
                Sleep(2000);
            }
        }
    }

    system("cls");
    gotoxy(80, 10);
    printf("버블 정렬 완료 후 배열:\n");
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
            printf("삽입 정렬 진행 중...\n");
			gotoxy(10, 20);
            printf("현재 배열 상태: ");
             gotoxy(80, 20);
            printArray(arr, size);
            Sleep(2000);
        }
        arr[j + 1] = key;
    }

    system("cls");
    gotoxy(80, 10);
    printf("삽입 정렬 완료 후 배열:\n");
     gotoxy(80,20);
    printArray(arr, size);
    Sleep(5000);
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 임시 배열 생성
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // 임시 배열에 데이터 복사
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 두 개의 임시 배열을 병합
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
        printf("병합 정렬 진행 중...\n");
         gotoxy(80,20);
        printf("현재 배열 상태: ");
        printArray(arr, right - left + 1);
        Sleep(2000);
    }

    // 남은 요소들 복사
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;

        system("cls");
        gotoxy(80, 10);
        printf("병합 정렬 진행 중...\n");
         gotoxy(80,20);
        printf("현재 배열 상태: ");
        printArray(arr, right - left + 1);
        Sleep(2000);
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;

        system("cls");
        gotoxy(80, 10);
        printf("병합 정렬 진행 중...\n");
         gotoxy(80,20);
        printf("현재 배열 상태: ");
        printArray(arr, right - left + 1);
        Sleep(2000);
    }

    // 임시 배열 메모리 해제
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 왼쪽 부분 배열 정렬
        mergeSort(arr, left, mid);

        // 오른쪽 부분 배열 정렬
        mergeSort(arr, mid + 1, right);

        // 정렬된 두 배열을 병합
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
                printf("쉘 정렬 진행 중...\n");
                 gotoxy(80,20);
                printf("현재 배열 상태: ");
                printArray(arr, size);
                Sleep(1000);
            }
            arr[j] = temp;
        }
    }

    system("cls");
    gotoxy(80, 10);
    printf("쉘 정렬 완료 후 배열:\n");
     gotoxy(80,20);
    printArray(arr, size);
    Sleep(5000);
}

void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // 왼쪽 자식이 루트보다 큰 경우
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // 오른쪽 자식이 루트보다 큰 경우
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // 가장 큰 값을 가진 노드와 교환
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        system("cls");
        gotoxy(80, 10);
        printf("힙 정렬 진행 중...\n");
         gotoxy(80,20);
        printf("현재 배열 상태: ");
        printArray(arr, size);
        Sleep(1000);

        // 교환 후 재귀적으로 heapify 호출
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    // 힙 구성
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // 힙에서 하나씩 요소를 꺼내 정렬
    for (int i = size - 1; i >= 0; i--) {
        // 루트와 마지막 노드 교환
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        system("cls");
        gotoxy(80, 10);
        printf("힙 정렬 진행 중...\n");
         gotoxy(80,20);
        printf("현재 배열 상태: ");
        printArray(arr, size);
        Sleep(1000);

        // 교환 후 힙을 재구성
        heapify(arr, i, 0);
    }

    system("cls");
    gotoxy(80, 10);
    printf("힙 정렬 완료 후 배열:\n");
     gotoxy(80,20);
    printArray(arr, size);
    Sleep(5000);
}



//----------------------------------------------------------------------------------------------------------------------//

