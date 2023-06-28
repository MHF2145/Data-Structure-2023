#include <iostream>

using namespace std;

typedef struct DLLC
{
	int data;
	DLLC *next;
	DLLC *prev;
} DLLC;

DLLC *head, *tail;

void init()
{
	head = NULL;
	tail = NULL;
}

int isEmpty()
{
	if (tail == NULL)
		return 1;
	else
		return 0;
}

void insertDepan(int databaru)
{
	DLLC *baru;
	baru = new DLLC;
	baru->data = databaru;
	baru->next = baru;
	baru->prev = baru;
	if (isEmpty() == 1)
	{
		head = baru;
		tail = baru;
		head->next = head;
		head->prev = head;
		tail->next = tail;
		tail->prev = tail;
	}
	else
	{
		baru->next = head;
		head->prev = baru;
		head = baru;
		head->prev = tail;
		tail->next = head;
	}
	cout << "Data masuk\n";
}

void insertBelakang(int databaru)
{
	DLLC *baru;
	baru = new DLLC;
	baru->data = databaru;
	baru->next = baru;
	baru->prev = baru;
	if (isEmpty() == 1)
	{
		head = baru;
		tail = baru;
		head->next = head;
		head->prev = head;
		tail->next = tail;
		tail->prev = tail;
	}
	else
	{
		tail->next = baru;
		baru->prev = tail;
		tail = baru;
		tail->next = head;
		head->prev = tail;
	}
	cout << "Data masuk\n";
}

void tampil()
{
	DLLC *bantu;
	bantu = head;
	if (isEmpty() == 0)
	{
		do
		{
			cout << bantu->data << " ";
			bantu = bantu->next;
		} while (bantu != tail->next);
		cout << endl;
	}
	else
		cout << "Masih kosong\n";
}

void tampilTerbalik()
{
	DLLC *bantu;
	bantu = tail;
	if (isEmpty() == 0)
	{
		do
		{
			cout << bantu->data << " ";
			bantu = bantu->prev;
		} while (bantu != head->prev);
		cout << endl;
	}
	else
		cout << "Masih kosong\n";
}

void hapusDepan()
{
	DLLC *hapus;
	int d;
	if (isEmpty() == 0)
	{
		if (head != tail)
		{
			hapus = head;
			d = hapus->data;
			head = head->next;
			tail->next = head;
			head->prev = tail;
			delete hapus;
		}
		else
		{
			d = head->data;
			head = NULL;
			tail = NULL;
		}
		cout << d << " terhapus\n";
	}
	else
		cout << "Masih kosong\n";
}

void hapusBelakang()
{
	DLLC *hapus;
	int d;
	if (isEmpty() == 0)
	{
		if (head != tail)
		{
			hapus = tail;
			d = hapus->data;
			tail = tail->prev;
			tail->next = head;
			head->prev = tail;
			delete hapus;
		}
		else
		{
			d = head->data;
			head = NULL;
			tail = NULL;
		}
		cout << d << " terhapus\n";
	}
	else
		cout << "Masih kosong\n";
}

int main()
{
	int input, temp;
	cout << "Menu" << endl;
	cout << "1. Insert Depan" << endl;
	cout << "2. Insert Belakang" << endl;
	cout << "3. Hapus Depan" << endl;
	cout << "4. Hapus Belakang" << endl;
	cout << "5. Tampil" << endl;
	cout << "6. Tampil Terbalik" << endl;
	do
	{
		cin >> input;

		switch (input)
		{
		case 1:
			cin >> temp;
			insertDepan(temp);
			break;

		case 2:
			cin >> temp;
			insertBelakang(temp);
			break;

		case 3:
			hapusDepan();
			break;

		case 4:
			hapusBelakang();
			break;

		case 5:
			tampil();
			break;

		case 6:
			tampilTerbalik();
			break;

		default:
			break;
		}
	} while (input != -1);
	return 0;
}