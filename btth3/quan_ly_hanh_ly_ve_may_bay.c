#include <stdio.h>
#include <string.h>

#define MAX_VE 100

int main() {
    struct VeMayBay {
        char maVe[15];
        char tenHanhKhach[50];
        char hangVe[20];
        float canNangHanhLy;
        float cuocHanhLy;
    };

    struct VeMayBay danhSachVe[MAX_VE];

    int soLuong;
    int i;
    int viTri = -1;

    char maVeCanTim[15];

    float tongCuoc = 0;
    int viTriNangNhat = 0;

    printf("Nhap so luong ve may bay: ");
    scanf("%d", &soLuong);

    if (soLuong < 1 || soLuong > MAX_VE) {
        printf("So luong ve khong hop le! Chuong trinh ket thuc.\n");
        return 0;
    }

    for (i = 0; i < soLuong; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);
        while (getchar() != '\n');

        printf("Ma ve PNR: ");
        fgets(danhSachVe[i].maVe, sizeof(danhSachVe[i].maVe), stdin);

        danhSachVe[i].maVe[strcspn(danhSachVe[i].maVe, "\n")] = '\0';

        printf("Ho ten hanh khach: ");
        fgets(danhSachVe[i].tenHanhKhach, sizeof(danhSachVe[i].tenHanhKhach), stdin);

        danhSachVe[i].tenHanhKhach[strcspn(danhSachVe[i].tenHanhKhach, "\n")] = '\0';

        printf("Hang ve (Business/Deluxe/Eco): ");
        fgets(danhSachVe[i].hangVe, sizeof(danhSachVe[i].hangVe), stdin);

        danhSachVe[i].hangVe[strcspn(danhSachVe[i].hangVe, "\n")] = '\0';

        do {
            printf("Khoi luong hanh ly ky gui (kg): ");
            scanf("%f", &danhSachVe[i].canNangHanhLy);

            if (danhSachVe[i].canNangHanhLy < 0) {
                printf("Khoi luong khong hop le! Vui long nhap lai.\n");
            }

        } while (danhSachVe[i].canNangHanhLy < 0);

        if (strcmp(danhSachVe[i].hangVe, "Business") == 0) {
            if (danhSachVe[i].canNangHanhLy <= 20) {
                danhSachVe[i].cuocHanhLy = 0;
            } else {
                danhSachVe[i].cuocHanhLy = (danhSachVe[i].canNangHanhLy - 20) * 50000;
            }

        } else {
            danhSachVe[i].cuocHanhLy = danhSachVe[i].canNangHanhLy * 50000;
        }
    }

    tongCuoc = 0;
    viTriNangNhat = 0;

    for (i = 0; i < soLuong; i++) {
        tongCuoc += danhSachVe[i].cuocHanhLy;

        if (danhSachVe[i].canNangHanhLy >
            danhSachVe[viTriNangNhat].canNangHanhLy) {

            viTriNangNhat = i;
        }
    }

    printf("\n");
    printf("================================== DANH SACH VE MAY BAY CHUYEN BAY ==================================\n");
    printf("----------------------------------------------------------------------------------------------------\n");

    printf("%-5s %-12s %-25s %-12s %12s %15s\n",
           "STT",
           "MA VE",
           "HO TEN HANH KHACH",
           "HANG VE",
           "HANH LY (KG)",
           "CUOC PHI (VND)");

    printf("----------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < soLuong; i++) {
        printf("%-5d %-12s %-25s %-12s %12.1f %15.0f\n",
               i + 1,
               danhSachVe[i].maVe,
               danhSachVe[i].tenHanhKhach,
               danhSachVe[i].hangVe,
               danhSachVe[i].canNangHanhLy,
               danhSachVe[i].cuocHanhLy);
    }

    printf("----------------------------------------------------------------------------------------------------\n");

    printf("Tong tien cuoc hanh ly toan chuyen: %.0f VND\n",
           tongCuoc);

    printf("Ve co hanh ly ky gui nang nhat: %s - %s (%.1f kg)\n",
           danhSachVe[viTriNangNhat].maVe,
           danhSachVe[viTriNangNhat].tenHanhKhach,
           danhSachVe[viTriNangNhat].canNangHanhLy);

    printf("\n--- CAP NHAT THONG TIN HANH LY ---\n");

    while (getchar() != '\n');

    printf("Nhap ma ve PNR can cap nhat hanh ly: ");
    fgets(maVeCanTim, sizeof(maVeCanTim), stdin);

    maVeCanTim[strcspn(maVeCanTim, "\n")] = '\0';

    viTri = -1;

    for (i = 0; i < soLuong; i++) {
        if (strcmp(danhSachVe[i].maVe, maVeCanTim) == 0) {
            viTri = i;
            break;
        }
    }

    if (viTri == -1) {
        printf("Khong tim thay ma ve PNR nay trong he thong!\n");
    } else {
        do {
            printf("Nhap can nang hanh ly ky gui moi (kg): ");
            scanf("%f", &danhSachVe[viTri].canNangHanhLy);

            if (danhSachVe[viTri].canNangHanhLy < 0) {
                printf("Khoi luong khong hop le! Vui long nhap lai.\n");
            }

        } while (danhSachVe[viTri].canNangHanhLy < 0);

        if (strcmp(danhSachVe[viTri].hangVe, "Business") == 0) {

            if (danhSachVe[viTri].canNangHanhLy <= 20) {
                danhSachVe[viTri].cuocHanhLy = 0;
            } else {
                danhSachVe[viTri].cuocHanhLy = (danhSachVe[viTri].canNangHanhLy - 20) * 50000;
            }

        } else {
            danhSachVe[viTri].cuocHanhLy = danhSachVe[viTri].canNangHanhLy * 50000;
        }

        printf("Tim thay ma ve %s. Da cap nhat cuoc hanh ly moi: %.0f VND.\n", danhSachVe[viTri].maVe, danhSachVe[viTri].cuocHanhLy);

        tongCuoc = 0;
        viTriNangNhat = 0;

        for (i = 0; i < soLuong; i++) {
            tongCuoc += danhSachVe[i].cuocHanhLy;

            if (danhSachVe[i].canNangHanhLy >
                danhSachVe[viTriNangNhat].canNangHanhLy) {

                viTriNangNhat = i;
            }
        }

        printf("\n");
        printf("================================ DANH SACH VE MAY BAY SAU CAP NHAT ================================\n");
        printf("----------------------------------------------------------------------------------------------------\n");

        printf("%-5s %-12s %-25s %-12s %12s %15s\n",
               "STT",
               "MA VE",
               "HO TEN HANH KHACH",
               "HANG VE",
               "HANH LY (KG)",
               "CUOC PHI (VND)");

        printf("----------------------------------------------------------------------------------------------------\n");

        for (i = 0; i < soLuong; i++) {

            printf("%-5d %-12s %-25s %-12s %12.1f %15.0f\n",
                   i + 1,
                   danhSachVe[i].maVe,
                   danhSachVe[i].tenHanhKhach,
                   danhSachVe[i].hangVe,
                   danhSachVe[i].canNangHanhLy,
                   danhSachVe[i].cuocHanhLy);
        }

        printf("----------------------------------------------------------------------------------------------------\n");

        printf("Tong tien cuoc hanh ly toan chuyen: %.0f VND\n",
               tongCuoc);

        printf("Ve co hanh ly ky gui nang nhat: %s - %s (%.1f kg)\n",
               danhSachVe[viTriNangNhat].maVe,
               danhSachVe[viTriNangNhat].tenHanhKhach,
               danhSachVe[viTriNangNhat].canNangHanhLy);
    }
    return 0;
}