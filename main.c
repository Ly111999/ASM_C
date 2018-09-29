#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char maSinhVien[10];
    char ten[50];
    char sdt[11];
} Sinhvien;

int dem = 0;
Sinhvien sinhvien[10];

int themmoisv() {

    char chon;
    for (int i = 0; i < 10; ++i) {
        if (dem == 10){
            printf(" Danh sách sinh viên đã bị đầy.\n");
            break;
        }
        printf("Nhập mã sinh viên: (nhập đủ 5 kí tự)\n");
        getchar();
        fgets(sinhvien[i].maSinhVien, 10, stdin);
        if (!strchr(sinhvien[i].maSinhVien, '\n')) {
            while (fgetc(stdin) != '\n');
        }

        //check mã

        printf("Nhập tên: \n");
        fgets(sinhvien[i].ten, 20, stdin);
        if (!strchr(sinhvien[i].ten, '\n')) {
            while (fgetc(stdin) != '\n');
        }
        printf("Nhập số điện thoại: \n");
        fgets(sinhvien[i].sdt, 11, stdin);
        if (!strchr(sinhvien[i].sdt, '\n')) {
            while (fgetc(stdin) != '\n');
        }
        dem++;

        printf("Bạn muốn nhập tiếp không? (y/n)\n");
        scanf("%s", &chon);
        if (chon == 'n' || chon == 'N') {
            break;
        }
    }
    return dem;
}

void hienthi() {
    printf("%d\n", dem);
    printf("%-10s%-20s%-10s%-20s%-10s%-20s\n", "", "Mã sinh viên", "|", "Tên sinh viên", "|", "Điện thoại");

    for (int i = 0; i < dem; ++i) {
        printf("%-10s%-34s%-10s%-60s%-10s%-20s\n", "", sinhvien[i].maSinhVien, "|", sinhvien[i].ten, "|",
               sinhvien[i].sdt);
    }
}

void ghiFile() {
    FILE *fp;
    fp = fopen("danhsachsinhvien.txt", "a+");

    fprintf(fp, "%-10s%-20s%-10s%-20s%-10s%-20s\n", "", "Mã sinh viên", "|", "Tên sinh viên", "|", "Điện thoại");
    for (int i = 0; i < dem; ++i) {
        fprintf(fp, "%-10s%-18s%-10s%-1s%-10s%-20s\n", "", sinhvien[i].maSinhVien, "|", sinhvien[i].ten, "|",
                sinhvien[i].sdt);
    }
    fclose(fp);

}

void docFile() {
    FILE *fp;
    fp = fopen("danhsachsinhvien.txt", "r");
    char buff[255];
    while (fgets(buff, 255, fp) != NULL) {
        printf("%s", buff);
    }
}

void menu() {
    while (true) {
        printf("\n----------MENU----------\n");
        printf("1. Thêm mới sinh viên.\n");
        printf("2. Hiển thị danh sách sinh viên.\n");
        printf("3. Lưu danh sách sinh viên ra file.\n");
        printf("4. Đọc danh sách sinh viên từ file.\n");
        printf("5. Thoát chương trình.\n");
        int luachon;
        printf("Vui lòng nhập lựa chọn của bạn: (1 đến 5)\n");
        scanf("%d", &luachon);
        switch (luachon) {
            case 1:
                themmoisv();
                break;
            case 2:
                hienthi();
                break;
            case 3:
                ghiFile();
                break;
            case 4:
                docFile();
                break;
            case 5:
                printf("Thoát chương trình.");
                exit(0);
            default:
                printf("Bạn nhập sai. Vui lòng nhập từ 1->5!");
                break;
        }
    }
}

int main() {
    menu();
    return 0;

}