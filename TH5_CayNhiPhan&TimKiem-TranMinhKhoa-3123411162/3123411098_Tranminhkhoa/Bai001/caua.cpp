#include <iostream>
using namespace std;

// Định nghĩa cấu trúc một nút trong cây nhị phân
struct node {
    int info;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

// Hàm khởi tạo cây
void initTree(TREE &t) {
    t = NULL;
}

// Hàm thêm một nút vào cây
void insertNode(TREE &t, int x) {
    if (t == NULL) {
        t = new NODE;
        t->info = x;
        t->pLeft = NULL;
        t->pRight = NULL;
    } else if (x < t->info) {
        insertNode(t->pLeft, x);
    } else {
        insertNode(t->pRight, x);
    }
}

// Hàm tính tổng giá trị của tất cả các nút trong cây
int TongNode(TREE Root) {
    if (Root == NULL) return 0;
    return Root->info + TongNode(Root->pLeft) + TongNode(Root->pRight);
}

// Hàm đếm số nút trong cây
int DemNode(TREE Root) {
    if (Root == NULL) return 0;
    return 1 + DemNode(Root->pLeft) + DemNode(Root->pRight);
}

// Hàm tính trung bình cộng các giá trị trong cây
float TrungBinhCong(TREE Root) {
    int s = TongNode(Root);
    int dem = DemNode(Root);
    if (dem == 0) return 0;
    return (float)s / dem;
}

// Hàm hiển thị cây theo thứ tự NLR (Preorder)
void preOrder(TREE t) {
    if (t) {
        cout << t->info << " ";
        preOrder(t->pLeft);
        preOrder(t->pRight);
    }
}

// Hàm kiểm tra
int main() {
    TREE t;
    initTree(t);

    // Chèn dữ liệu vào cây
    insertNode(t, 5);
    insertNode(t, -3);
    insertNode(t, 8);
    insertNode(t, -7);
    insertNode(t, 2);
    insertNode(t, 6);
    insertNode(t, 10);

    cout << "Duyệt cây theo thứ tự NLR: ";
    preOrder(t);
    cout << endl;

    cout << "Trung bình cộng các nút trong cây: " << TrungBinhCong(t) << endl;

    return 0;
}
