#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string top = "<html>\n<head><title>Generated Page</title>\n<link rel=\"stylesheet\" href=\"style.css\"/>\n</head>\n<body>\n";
const string bottom = "\n</body>\n</html>";

// Boolean value which stops loop and restart user to main menu//
bool restart = true;


void create_page(ofstream &file);
void table_menu(ofstream &file);
void table_parameters(ofstream &file);
void navigation_bar(ofstream& file);
void create_list(ofstream& file);


int main() {

	ofstream file("index.html");

	file << top;
	create_page(file);
	file << bottom;
    
   	file.close();

	return 0;
}




void table_menu(ofstream& file) {

	int choose, j, num, select, th_num, l, row_td, repeat;
	string td, link, image_link, image_name, link_name, th;
	
	do {

		cout << "####################\n";
		cout << "Table creation Menu:\n";
		cout << "####################\n";
		cout << "--------------------\n";
		cout << "1. Create Table\n";
		cout << "2. Create Header\n";
		cout << "3. Create Rows\n";
		cout << "0. Back\n";
		cout << "\n";

		cin >> choose;
		cin.ignore();
		switch (choose) {
		case 1:
			system("cls");
			table_parameters(file);
			cout << "Table is created succsesfully.......\n";
			break;
		case 2:
			system("cls");
			cout << "How Many Headers You need?\n";
			cin >> th_num;
			cin.ignore();
			file << "<tr>\n";
			for (l = 1; l <=th_num; l++) {
				cout << "Write information to your header number " << l << endl;
				getline(cin, th);
				file << "<th><h2>" << th << "</h2></th>\n";
				system("cls");
			}
			file << "</tr>\n";
			break;
		case 3:
			cout << "How Many Rows You Need ?\n";
			cin >> num;
			cin.ignore();
			system("cls");
			cout << "How Much Data You Will Put Into Row ?\n";
			cin >> row_td;
			cin.ignore();
			for (repeat = 1; repeat<= num; repeat++){   // ciklas kuris sukasi tiek kiek eiluciu bus
				if (row_td == 0) {
						cout << "Select Information For Your Row " << repeat << endl;
						cout << "1. Create Liink\n";
						cout << "2. Put Image\n";
						cout << "3. Write Text\n";
						cin >> select;
						system("cls");
						cin.ignore();
						if (select == 1) {
							cout << "Write Link\n";
							getline(cin, link);
							system("cls");
							cout << "Write Name For Your Link\n";
							getline(cin, link_name);
							system("cls");
							file << "<tr>\n<td>\n<a href=\"" << link << "\">" << link_name << "</a>\n</td>\n</tr>";
						}
						else if (select == 3) {
							cout << "Write Information\n";
							getline(cin, td);
							system("cls");
							file << "<tr>\n<td><p>" << td << "</p></td>\n</tr>";
						}
						else if (select == 2) {
							cout << "Write image link\n";
							getline(cin, image_link);
							system("cls");
							cout << "Write alternative image information in case image won't show up\n";
							getline(cin, image_name);
							system("cls");
							file << "<tr>\n<td>\n<img src=\"" << image_link << "\" alt=\"" << image_name << "\"/>\n</td></tr>\n";
						}
					
				}
				else if (row_td > 0)  {
					file << "<tr>\n";
					for (j = 1; j <= row_td; j++) {
						cout << "Select Information Type For Your Row " << j << endl;
						cout << "1. Create Liink\n";
						cout << "2. Put Image\n";
						cout << "3. Write Text\n";
						cin >> select;
						system("cls");
						cin.ignore();
						if (select == 1) {
							cout << "Write link\n";
							getline(cin, link);
							system("cls");
							cout << "Write name for your link\n";
							getline(cin, link_name);
							system("cls");
							file << "<td>\n<a href=\"" << link << "\">" << link_name << "</a>\n</td>\n</tr>\n";
						}
						else if (select == 3) {
							cout << "Write information\n";
							getline(cin, td);
							system("cls");
							file << "<td><p>" << td << "</p></td>\n";
						}
						else if (select == 2) {
							cout << "Write image link\n";
							getline(cin, image_link);
							system("cls");
							cout << "Write alternative image information in case image won't show up\n";
							getline(cin, image_name);
							system("cls");
							file << "<td>\n<img src=\"" << image_link << "\" alt=\"" << image_name << "\"/>\n</td></tr>\n";
						}
						
					}

					
				}
				
				file << "</tr>\n";
			}
			break;
			file << "</table>\n";
		case 0:
			system("cls");
			restart = false;
			break;

		default:
			break;
		}
	} while (choose != 0);
}

void create_page(ofstream& file) {

	int choice, p, i, img_width, img_height;
	string title, paragraph, img_link, img_align, img_alt, link_add, link_name;

	do {
		cout << "#########################" << endl;
		cout << " Web Page Generator 1.0v " << endl;
		cout << "#########################" << endl;
		cout << "-------------------------" << endl;
		cout << "1. Create Navigation Bar" << endl;
		cout << "2. Create Page Title" << endl;
		cout << "3. Create New Paragraph" << endl;
		cout << "4. Table Menu" << endl;
		cout << "5. Put Image" << endl;
		cout << "6. Put Link" << endl;
		cout << "7. Create List" << endl;
		cout << "0. Exit" << endl;
		cout << "\n";


		cin >> choice;
		cin.ignore();
		switch (choice) {


		case 1:
		  system("cls");
			navigation_bar(file);
		  break;


		case 2:
		  system("cls");
			cout << "Write Titile Of Your Page:\n";
			getline(cin, title);
			file << "<h1>" << title << "</h1>\n";
			system("cls");
		  break;


		case 3:
			system("cls");
			cout << "How many paragraphs you want to make?" << endl;
			cin >> p;
			cin.ignore();
			for (i = 1; i <= p; i++) {
				cout << "Write information to paragraphs:" << endl;
				getline(cin, paragraph);
				file << "<p>" << paragraph << "</p>\n";
				cout << "Paragraph is created !!\n";
				system("cls");
			}
			break;
		case 4:
			system("cls");
			restart = true;
			while (restart) {
				table_menu(file);
				if (restart == false) {
					break;
				}
			}
			break;
		case 5:
			system("cls");
			cout << "Write Link To Image\n";
			getline(cin, img_link);
			system("cls");
			cout << "Choose Alignment ( Left, Right )\n";
			getline(cin, img_align);
			system("cls");
			cout << "Width In Pixels\n";
			cin >> img_width;
			system("cls");
			cout << "Height In Pixels\n";
			cin >> img_height;
			cin.ignore();
			system("cls");
			cout << "Alternative Description\n";
			getline(cin, img_alt);
			system("cls");
			file << "<img src=\"" << img_link << "\" width=\"" << img_width << "px\" height=\"" << img_height << "px\" align=\"" << img_align << "\" alt=\"" << img_alt << "\">\n";
			cout << "Image Is Put Succsessfully...\n";
			break;
		case 6:
			system("cls");
			cout << "Write Link\n";
			getline(cin, link_add);
			system("cls");
			cout << "Write Name For Your link\n";
			getline(cin, link_name);
			system("cls");
			file << "<a href=\"" << link_add << "\">" << link_name << "</a>\n";
			cout << "Link Is Put Succsessfully...\n";
			break;

		case 7:

		  system("cls");
			create_list(file);
		  break;

		case 0:
			system("cls");
			cout << "\n";
			cout << "Exiting program...\n";
			break;
		default:
			cout << "Option " << choice << " is not available!\n";
			break;
		}
	} while (choice != 0);

}

void table_parameters(ofstream& file) {

	int b_size, width, height;
	cout << "Basic Parametres\n";
	cout << "----------------\n";
	cout << "Border size?: 0-1\n";
	cout << "Width in pixels\n";
	cout << "Height in pixels\n";
		cin >> b_size;
	 system("cls");
	cout << "Width\n";
		cin >> width;
	 system("cls");
	cout << "Height\n";
		cin >> height;
	 system("cls");
	 file << "<table border=\"" << b_size << "\" width=\"" << width << "px\" height=\"" << height << "px\">\n";
}

void navigation_bar(ofstream& file) {

	int count, i;
	string title, link, name;

		file << "<header>\n";
			cout << "Write Title Of Your Bar\n";
			getline(cin, title);
		file << "<h1 class=\"title\">" << title << "</h1>\n";

		file << "<nav>\n";
			cout << "How Many Buttons You Need ?\n";
			cin >> count;
			cin.ignore();
			if (count > 0) {
				file << "<ul class=\"ul_nav\">\n";
				for (i = 1; i <= count; i++) {
					cout << "Write Link For Your Button " << i << endl;
					getline(cin, link);
					cout << "Write Name For Button\n";
					getline(cin, name);
					file << "<li class=\"li_nav\"><a class=\"a_nav\" href=\"" << link << "\">" << name << "</a></li>\n";
				}
				file << "</ul>\n";
			}
			else {
				cout << "You Selected 0\n";
			}
		file << "</nav>\n";
		file << "</header>\n";
}
void create_list(ofstream& file) {

	int i, num, type;
	string data;

	cout << "What Type List You Want To Put?\n";
	cout << "|| 1. Bullet || || 2. Number ||\n";
		cin >> type;
		cin.ignore();
			if (type == 1) {
				file << "<ul>\n";
					cout << "How Long Your List Will Be?\n";
					cin >> num;
					cin.ignore();
						for(i=1; i<=num; i++){
							cout << "Write Information In Your List " << i << endl;
							getline(cin, data);
							file << "<li>" << data << "</li>\n";
							system("cls");
						}
				file << "</ul>\n";
			}
			else if (type == 2) {
				file << "<ol>\n";
					cout << "How Long Your List Will Be?\n";
					cin >> num;
					cin.ignore();
						for (i=1; i<=num; i++) {
							cout << "Write Information In Your List " << i << endl;
							getline(cin, data);
							file << "<li>" << data << "</li>\n";
							system("cls");
						}
				file << "</ol>\n";
			}
			else {
				system("cls");
				cout << "Your Selection Is Wrong!!!....\n";
			}

}
