#include <stdio.h> //library-library yang digunakan
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main() //fungsi utama
{
	system("cls"); //fungsi cls adalah membersihkan layar program
	char username[6]; //deklarasi array
    char password[5];

    login: // login
    printf("Username: ");
    scanf("%s", username);

    printf("password: ");
    scanf("%s", password);

    if((strcmp(username,"admin")==0)&&(strcmp(password,"root")==0))//isi dari file login bin
        {
        printf("status: login sukses");
    } else {
        printf("status: login gagal");
        goto login;
    }
    menu();
	return 0;
}

void menu(); //fungsi untuk membuat menu
void tampil_novel(); //fungsi untuk membuat tampilkan data novel
void cari_novel();	//Fungsi untuk membuat cari data novel
void tambah_novel();	//Fungsi untuk membuat bagian tambah data novel
void hapus_novel();	//Fungsi untuk membuat bagian hapus data novel
void edit_novel();	//Fungsi untuk membuat bagian edit data novel

struct DATA { //struct data untuk file.txt
	char judul[80];
	int kd;
	char pengarang[80];
	int harga;
}tambah,cek,hapus,temp;

//membuat menu pilihan
void menu(){ //fungsi utama untuk membuat menu
	int pilih;
	menu: //pilihan menu
		system("cls");
		printf("===========================================\n");
		printf("\tmenampilkan menu Novel\n");
		printf("===========================================\n\n");
		printf("MENU :");
		printf("\n1 Tampil Data novel");
		printf("\n2 Cari Data novel");
		printf("\n3 Tambah Data novel");
		printf("\n4 Hapus Data novel");
		printf("\n5 Edit Data novel");
		printf("\n6 Keluar");
		printf("\n===========================================");
		printf("\n\nPilih [1-5] : ");
		scanf("%d", &pilih);

		switch(pilih){ //pililah menu
			case 1:tampil_novel();
				break;
			case 2:cari_novel();
				break;
			case 3:tambah_novel();
				break;
			case 4:hapus_novel();
				break;
			case 5:edit_novel();
				break;
			case 6:close();
				break;
			default:printf("\nMohon Maaf Pilihan Anda Salah !"); //jika input salah
				getche();
				goto menu;
		}
}

void tampil_novel()//fungsi untuk menampilkan novel
{
	FILE *view;
	view = fopen("DATA/novel.txt","r"); //membuka file dalam folder data dengan nama novel.txt
	int test=0;
	system ("cls");
	printf ("KODE\t\tJUDUL\t\tPENGARANG\t\tHARGA\n");
	while (fscanf (view,"%d;%[^;];%[^;];%d;\n",&tambah.kd,tambah.judul,tambah.pengarang,&tambah.harga)!=EOF)//untuk menampilkan atribut menu
	{
		printf("%d\t\t%s\t%s\t\t%d\t\t\n",tambah.kd,tambah.judul,tambah.pengarang,tambah.harga);
		test++;
	}
	fclose(view); //file di tutup

	if(test==0)
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nEnter 1 untuk kembali ke menu utama dan 0 untuk keluar : ");//pilihan untuk lanjut atau tidak
    switch(getch()){
    	case '1': menu();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}
void cari_novel() //fungsi proses cari novel
{
	FILE *ptr; //pointer ke file
	int test=0;
	system("cls");
	ptr=fopen("DATA/novel.txt","r"); //filedibuka dan mode read
	system("cls");
	printf("Input kode novel : ");
	scanf("%d", &cek.kd);
	while(fscanf (ptr,"%d;%[^;];%[^;];%d;\n",&tambah.kd,tambah.judul,tambah.pengarang,&tambah.harga)!=EOF){
		if(tambah.kd==cek.kd){
			test=1;
    printf("KODE:%d\t",tambah.kd);
    printf("JUDUL:%s\t",tambah.judul);
    printf("PENGARANG:%s\t",tambah.pengarang);
    printf("HARGA:%d\t",tambah.harga);
		}
	}
	fclose(ptr);
	if(test!=1){
		system("cls");
		detail_print:
		printf("\nData tidak ditemukan !\a\a\a");
		detail_invalid:
		printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': cari_novel();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto detail_invalid;
        }
	}else{
		detail_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto detail_valid;
       	}
    }

}

void tambah_novel(){ //menambhakan data novel
	FILE *ptr,*ptr1;
	int count=0;

	ptr =fopen("novel.txt","a");
		system("cls");
		ptr1 =fopen("novel.txt","r");
		while (fscanf (ptr1,"%d;%[^;];%[^;];%d;\n",&tambah.kd,&tambah.judul,&tambah.pengarang,&tambah.harga)!=EOF)
		{
			tambah.kd++;
		}
		cek.kd = tambah.kd;
		fclose(ptr1);
		printf ("Masukan judul novel : ");fflush(stdin);
		scanf ("%[^\n]",tambah.judul);
		printf ("masukan pengarang : ");fflush(stdin);
		scanf ("%[^\n]",tambah.pengarang);
		printf ("Masukan harga novel : ");fflush(stdin);
		scanf ("%d",&tambah.harga);

		fprintf(ptr,"%d;%s;%s;%d;\n",tambah.kd,tambah.judul,tambah.pengarang,tambah.harga);
		fclose(ptr);

		printf("\n\nData novel Sudah Disimpan !");
		add_invalid:
		printf("\n\n\tKetik 1 untuk kembali ke menu utama dan 0 untuk keluar : ");

		switch(getch()){
    		case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}

void hapus_novel() //proses hapus data
{
	FILE *lama, *baru;
	int test=0;
	lama = fopen("DATA/novel.txt","r");
	baru = fopen("DATA/new.txt","w");
	system("cls");
	printf("Input kode novel yang akan di hapus : ");
	scanf("%d", &hapus.kd);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;\n",&tambah.kd,tambah.judul,tambah.pengarang,&tambah.harga)!=EOF)
	{
		if(tambah.kd != hapus.kd){
			fprintf(baru,"%d;%s;%s;%d;\n",tambah.kd,tambah.judul,tambah.pengarang,tambah.harga);
		}
		else{
			test++;
			printf("\nkode novel : %d dengan judul : %s\n",tambah.kd,tambah.judul);
			printf("\nBerhasil dihapus dari Daftar !");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("novel.txt");
	rename("new.txt","novel.txt");
		if(test==0){
            printf("\nData Tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': hapus_novel();
            		break;
            	case '1': menu();
            		break;
            	case '2': close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }
    else{
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }

}

void edit_novel() //proses menambah data
{
	int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("DATA/novel.txt","r");
	baru = fopen ("DATA/new.txt","w");
	system("cls");

	printf ("Masukan kode novel : ");
	scanf ("%d",&cek.kd);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;\n",&tambah.kd,tambah.judul,tambah.pengarang,&tambah.harga)!=EOF)
	{
		if(tambah.kd == cek.kd)
		{
			test=1;
			ganti:
				printf("\nkode novel: %d dengan judul: %s",tambah.kd,tambah.judul);
				printf("\n\nData yang akan diganti : ");
				printf("\n1. judul");
				printf("\n2. pengarang");
				printf("\n3. harga");
				scanf("%d",&pilih);

				if(pilih == 1)
				{
					printf("\nMasukan Data judul Baru : ");fflush(stdin);
					scanf("%[^\n]",cek.judul);
					strcpy(tambah.judul,cek.judul);
                    fprintf(baru,"%d;%s;%s;%d;\n",tambah.kd,tambah.judul,tambah.pengarang,tambah.harga);
					printf("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 2)
				{
					printf("\nMasukan Data pengarang baru : ");fflush(stdin);
					scanf("%[^\n]",cek.pengarang);
					strcpy(tambah.pengarang,cek.pengarang);
                    fprintf(baru,"%d;%s;%s;%d;\n",tambah.kd,tambah.judul,tambah.pengarang,tambah.harga);
					printf("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 3)
				{
					printf("\nMasukan Data harga Baru : ");
					scanf("%d",&cek.harga);
					strcpy(tambah.harga,cek.harga);
					fprintf(baru,"%d;%s;%s;%d;\n",tambah.kd,tambah.judul,tambah.pengarang,tambah.harga);
					printf("\nPerubahan Sudah Disimpan !");
				}

				else{
					printf("\n\nInput Anda Salah !");
					getche();
					goto ganti;
				}
		}
		else{
			fprintf(baru,"%d;%s;%s;%d;\n",tambah.kd,tambah.judul,tambah.pengarang,tambah.harga);
		}
	}

	fclose(lama);
	fclose(baru);
	remove("novel.txt");
	rename("new.txt","DATA/novel.txt");
	if(test!=1){
		system("cls");
        printf("\nData Tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': edit_novel();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }
    else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}
