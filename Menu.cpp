#include "Menu.h"

//General methods:

int glob = 0;
int globStream = 0;

void mainMenu() {

    std::ofstream ifs;
    ifs.open("../textTmp.txt", std::ofstream::out | std::ofstream::trunc);
    ifs.close();

    fstream userOutput;
    userOutput.open("../console_output.txt", ios::app);

    fstream textTmp;
    textTmp.open("../textTmp.txt", ios::app);

    ifstream fileInput;
    fileInput.open("../fileInput.txt", ios::in);

    char* inputArr = new char [1024];

    if (fileInput.is_open()) {
        for (int i = 0; i < 1024; i++) {
            fileInput >> inputArr[i];
        }
    }

    globStream = chooseStream();
    char c = chooseGeoObject(globStream, userOutput, textTmp, inputArr);

    fileInput.close();
    userOutput.close();
    textTmp.close();

    if (c == 'y') {

        std::ifstream src("../textTmp.txt", std::ios::binary);
        std::ofstream dst("../console_output.txt", std::ios::app);
        dst << src.rdbuf();
    }

    std::ofstream ofs;
    ofs.open("../textTmp.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

int chooseStream() {


    int option;
    bool ckr = false;
    char* optTmp = new char[100];

    do {
        cout << "Choose your preferred input:\n1. Console;\n2. File;\n";
        cin >> optTmp;

        if (strcmp(optTmp, "1") == 0) {
            option = 1;
            ckr = true;
        }
        else if (strcmp(optTmp, "2") == 0) {
            option = 2;
            ckr = true;
        }
        else
            option = 0;

        if (!ckr)
            cout << "\nPlease enter a valid command (1 or 2)!\n";

    } while (option != 1 && option != 2);

    if (option == 1) {
        cout << "You have chosen \"Console\" output!\n";
    }
    if (option == 2) {
        cout << "You have chosen \"File\" output!\n";
    }

    return option;

}

char chooseGeoObject(int opt, std::fstream& userOutput, std::fstream& textTmp, const char* inputArr) {

    int option = -1;
    bool ckr = false;
    char* optTmp = new char[100];
    char qstn = '/';
    char fi = '/';
    char fi2 = '/';
    char* str = new char[20];

    do {
        do {
            cout << "Choose a geometrical object:"
                    "\n1. Point;\n2. Vector;\n3. Line\n4. Segment\n5. Triangle\n6. Tetrahedron\n"
                    "0. Exit\n";
            if (opt == 2) {
                fi = inputArr[glob];
                fi2 = inputArr[glob+1];
                glob++;
                glob++;
            } else {
                cin >> optTmp;
            }

            if ((strcmp(optTmp, "1") == 0) || (fi == '1' && fi2 == '\'')) {
                option = 1;
                ckr = true;
            }
            else if ((strcmp(optTmp, "2") == 0) || (fi == '2' && fi2 == '\'')) {
                option = 2;
                ckr = true;
            }
            else if ((strcmp(optTmp, "3") == 0) || (fi == '3' && fi2 == '\'')) {
                option = 3;
                ckr = true;
            }
            else if ((strcmp(optTmp, "4") == 0) || (fi == '4' && fi2 == '\'')) {
                option = 4;
                ckr = true;
            }
            else if ((strcmp(optTmp, "5") == 0) || (fi == '5' && fi2 == '\'')) {
                option = 5;
                ckr = true;
            }
            else if ((strcmp(optTmp, "6") == 0) || (fi == '6' && fi2 == '\'')) {
                option = 6;
                ckr = true;
            }
            else if ((strcmp(optTmp, "0") == 0) || (fi == '0' && fi2 == '\'')) {
                option = 0;
                ckr = true;
            }
            else
                option = -1;

            if (!ckr) {
                cout << "\nPlease enter a valid command (0 to 6)!\n";
                if (globStream == 2) {
                    exit(0);
                }
            }
        } while (option < 0 || option > 6);

        switch (option) {
            case 1:
                cout << "You have chosen \"Point\".\n";
                menuPoint(opt, userOutput, textTmp, inputArr);
                break;
            case 2:
                cout << "You have chosen \"Vector\".\n";
                menuVector(opt, userOutput, textTmp, inputArr);
                break;
            case 3:
                cout << "You have chosen \"Line\".\n";
                menuLine(opt, userOutput, textTmp, inputArr);
                break;
            case 4:
                cout << "You have chosen \"Segment\".\n";
                menuSegment(opt, userOutput, textTmp, inputArr);
                break;
            case 5:
                cout << "You have chosen \"Triangle\".\n";
                menuTriangle(opt, userOutput, textTmp, inputArr);
                break;
            case 6:
                cout << "You have chosen \"Tetrahedron\".\n";
                menuTetrahedron(opt, userOutput, textTmp, inputArr);
                break;
            case 0:
                cout << "Would you like to export all results to a file (y/n)?\n";
                cin >> qstn;
                while (qstn != 'y' && qstn != 'n') {
                    cout << "Please enter a valid command (y/n)!\n";
                    cin >> qstn;

                    if (qstn == 'y')
                        cout << "All results are exported!\n";
                }
                cout << "\nExiting...\n";
                cout << "\nExit completed\n";
                break;
        }
    } while (option != 0);
    return qstn;
}

//Object specific methods:

//For class Point:

void menuPoint(int stream, std::fstream& userOutput, std::fstream& textTmp, const char* inputArr) {

    int option = -1;
    bool ckr = false;
    bool res;
    char* optTmp = new char[100];
    char fi = '/';
    char fi2 = '/';

    Point p1 = createNewPoint(inputArr);

    cout << "\nPoint\n" << p1;
    textTmp << "\nPoint\n" << p1;

    do {
        do {

            cout << "\nPlease choose an operation with your Point:\n";
            cout << "1. Check if two points coincide.\n";
            cout << "0. Return - Select a new object.\n";
            if (globStream == 2) {
                fi = inputArr[glob];
                fi2 = inputArr[glob+1];
                glob++;
                glob++;
            } else {
                cin >> optTmp;
            }

            if ((strcmp(optTmp, "1") == 0) || (fi == '1' && fi2 == '\'')) {
                option = 1;
                ckr = true;
            }
            else if ((strcmp(optTmp, "0") == 0) || (fi == '0' && fi2 == '\'')) {
                option = 0;
                ckr = true;
            }
            else {
                option = -1;
                ckr = false;
            }

            if (!ckr) {
                cout << "\nPlease enter a valid command (Press 1 or 0)!\n";
                if (globStream == 2) {
                    exit(0);
                    return;
                }
            }
        } while (option < 0 || option > 1);

        switch (option) {
            case 1:
                Point p2 = createNewPoint(inputArr);
                cout << "Result:\n";
                textTmp << "Result:\n";
                res = p1 == p2;
                if (res) {
                    cout << "True, Point" << p1 << " and Point" << p2 << " coincide.\n";
                    textTmp << "True, Point" << p1 << " and Point" << p2 << " coincide.\n";
                }
                else {
                    cout << "False, Point" << p1 << " and Point" << p2 << " do not coincide.\n";
                    textTmp << "False, Point" << p1 << " and Point" << p2 << " do not coincide.\n";
                }

                cout << "Additional objects for the operation: " << p2 << '\n';
                textTmp << "Additional objects for the operation: " << p2 << '\n';
        }
    } while (option != 0);

}

Point createNewPoint(const char* inputArr) {
    double x, y, z;
    bool validation = false;
    char fi = '/';

    cout << "Please enter values for a new Point:\n";
    do {
        if (globStream == 2) {
            fi = inputArr[glob];
            glob++;
            x = (double) fi;
            x = x - 48;
        } else {
            cout << "x = ";
            cin >> x;
        }
        if (cin.good())
        {
            validation = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number!" << endl;
            validation = false;
        }
    } while (!validation);

    validation = false;

    do {
        if (globStream == 2) {
            fi = inputArr[glob];
            glob++;
            y = (double) fi;
            y = y - 48;
        } else {
            cout << "y = ";
            cin >> y;
        }
        if (cin.good())
        {
            validation = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number!" << endl;
            validation = false;
        }
    } while (!validation);

    validation = false;

    do {
        if (globStream == 2) {
            fi = inputArr[glob];
            glob++;
            z = (double) fi;
            z = z - 48;
        } else {
            cout << "z = ";
            cin >> z;
        }
        if (cin.good())
        {
            validation = true;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number!" << endl;
            validation = false;
        }
    } while (!validation);

    return Point(x, y, z);
}

//For class Vector:

void menuVector(int stream, std::fstream& userOutput, std::fstream& textTmp, const char* inputArr) {

    int option = -1;
    bool ckr = false;
    char* optTmp = new char[100];
    char fi = '/';
    char fi2 = '/';
    char fi3 = '/';


    bool validation = false;

    Vector v1 = createNewVector(inputArr);
    Vector v2;
    Vector v3;

    cout << "\nVector\n" << v1;
    textTmp << "\nVector\n" << v1;

    do {
        do {
            cout << "\nPlease choose an operation with your Vector:\n";
            cout << "1. Vector magnitude calculation.\n";
            cout << "2. Vector direction calculation.\n";
            cout << "3. Check for zero vector.\n";
            cout << "4. Check for parallelism of two vectors.\n";
            cout << "5. Check for perpendicularity of two vectors.\n";
            cout << "6. Addition of two vectors.\n";
            cout << "7. Multiplication of a vector by a real number.\n";
            cout << "8. Scalar multiplication of two vectors.\n";
            cout << "9. Vector multiplication of two vectors.\n";
            cout << "10. Mixed multiplication of three vectors.\n";
            cout << "0. Return - Select a new object.\n";
            if (globStream == 2) {
                fi = inputArr[glob];
                fi2 = inputArr[glob+1];
                fi3 = inputArr[glob+2];
                glob++;
                glob++;
                if (fi3 == '\'')
                    glob++;
            } else {
                cin >> optTmp;
            }

            if ((strcmp(optTmp, "1") == 0) || (fi == '1' && fi2 == '\'')) {
                option = 1;
                ckr = true;
            }
            else if ((strcmp(optTmp, "2") == 0) || (fi == '2' && fi2 == '\'')) {
                option = 2;
                ckr = true;
            }
            else if ((strcmp(optTmp, "3") == 0) || (fi == '3' && fi2 == '\'')) {
                option = 3;
                ckr = true;
            }
            else if ((strcmp(optTmp, "4") == 0) || (fi == '4' && fi2 == '\'')) {
                option = 4;
                v2 = createNewVector(inputArr);
                ckr = true;
            }
            else if ((strcmp(optTmp, "5") == 0) || (fi == '5' && fi2 == '\'')) {
                option = 5;
                v2 = createNewVector(inputArr);
                ckr = true;
            }
            else if ((strcmp(optTmp, "6") == 0) || (fi == '6' && fi2 == '\'')) {
                option = 6;
                v2 = createNewVector(inputArr);
                ckr = true;
            }
            else if ((strcmp(optTmp, "7") == 0) || (fi == '7' && fi2 == '\'')) {
                option = 7;
                ckr = true;
            }
            else if ((strcmp(optTmp, "8") == 0) || (fi == '8' && fi2 == '\'')) {
                option = 8;
                v2 = createNewVector(inputArr);
                ckr = true;
            }
            else if ((strcmp(optTmp, "9") == 0) || (fi == '9' && fi2 == '\'')) {
                option = 9;
                v2 = createNewVector(inputArr);
                ckr = true;
            }
            else if ((strcmp(optTmp, "10") == 0) || (fi == '1' && fi2 == '0' && fi3 == '\'')) {
                glob++;
                option = 10;
                v2 = createNewVector(inputArr);
                v3 = createNewVector(inputArr);
                ckr = true;

            }
            else if ((strcmp(optTmp, "0") == 0) || (fi == '0' && fi2 == '\'')) {
                option = 0;
                ckr = true;
            }
            else
                option = -1;

            if (!ckr) {
                cout << "\nPlease enter a valid command (Press 0 to 10)!\n";
                if (globStream == 2) {
                    exit(0);
                }
            }
        } while (option < 0 || option > 11);

        try
        {
            switch (option) {
                case 1:
                    cout << "\nMagnitude = " << v1.getMagnitude();
                    textTmp << "\nMagnitude = " << v1.getMagnitude();
                    break;
                case 2:
                    cout << "\nDirection = " << v1.getDirection();
                    textTmp << "\nDirection = " << v1.getDirection();
                    break;
                case 3:
                    cout << "\nNull vector verification: ";
                    textTmp << "\nNull vector verification: ";
                    if (v1.isNullVector()) {
                        cout << "True\n";
                        textTmp << "True\n";
                    }
                    else {
                        cout << "False\n";
                        textTmp << "False\n";
                    }
                    break;
                case 4:
                    cout << "\nIs Vector" << v1 << " parallel to Vector" << v2 << ":\n";
                    textTmp << "\nIs Vector" << v1 << " parallel to Vector" << v2 << ":\n";

                    if (v1.isParallelWith(v2)) {
                        cout << "True\n";
                        textTmp << "True\n";
                    }
                    else {
                        cout << "False\n";
                        textTmp << "False\n";
                    }
                    break;
                case 5:
                    cout << "\nIs Vector" << v1 << " perpendicular to Vector" << v2 << ":\n";
                    textTmp << "\nIs Vector" << v1 << " perpendicular to Vector" << v2 << ":\n";

                    if (v1.isPerpendicularWith(v2)) {
                        cout << "True\n";
                        textTmp << "True\n";
                    }
                    else {
                        cout << "False\n";
                        textTmp << "False\n";
                    }
                    break;
                case 6:
                    cout << "\nV" << v1 << " + V" << v2 << " = V" << v1 + v2;
                    textTmp << "\nV" << v1 << " + V" << v2 << " = V" << v1 + v2;
                    break;
                case 7:
                    double input;
                    cout << "Enter a number:\n";
                    do {
                        if (globStream == 2) {
                            fi = inputArr[glob];
                            glob++;
                            input = (double) fi;
                            input = input - 48;
                        } else {
                            cout << "Num =";
                            cin >> input;
                        }
                        if (cin.good())
                        {
                            validation = true;
                        }
                        else
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Please enter a number!" << endl;
                            validation = false;
                        }
                    } while (!validation);

                    validation = false;
                    cout << "\nV" << v1 << " + " << input << " = V" << v1 * input;
                    textTmp << "\nV" << v1 << " + " << input << " = V" << v1 * input;
                    break;
                case 8:
                    cout << "\nV" << v1 << " * V" << v2 << " = " << v1 * v2;
                    textTmp << "\nV" << v1 << " * V" << v2 << " = " << v1 * v2;
                    break;
                case 9:
                    v3 = v1 ^ v2;
                    cout << "\nV" << v1 << " ^ V" << v2 << " = V" << v3;
                    textTmp << "\nV" << v1 << " ^ V" << v2 << " = V" << v3;
                    break;
                case 10:
                    double res = v1(v2, v3);
                    cout << "\n(V" << v1 << " x V" << v2 << ") . V" << v3 << " = " << res;
                    textTmp << "\n(V" << v1 << " x V" << v2 << ") . V" << v3 << " = " << res;
                    break;
            }
        }
        catch (const VectorLengthException & e)
        {
            cout << e.what() << endl;
        }

        bool v2Check = v2.getX() == 0 && v2.getY() == 0 && v2.getZ() == 0;
        bool v3Check = v3.getX() == 0 && v3.getY() == 0 && v3.getZ() == 0;

        if ((!v2Check) && (!v3Check)) {
            cout << "\nAdditional objects for the operation: " << v2 << '\t' << v3 << '\n';
            textTmp << "\nAdditional objects for the operation: " << v2 << '\t' << v3 << '\n';
            v2.setX(0);
            v2.setY(0);
            v2.setZ(0);
            v3.setX(0);
            v3.setY(0);
            v3.setZ(0);
        }
        else if (v2Check && (!v3Check)) {
            cout << "\nAdditional objects for the operation: " << v3 << '\n';
            textTmp << "\nAdditional objects for the operation: " << v3 << '\n';
            v3.setX(0);
            v3.setY(0);
            v3.setZ(0);
        }
        else if (v3Check && (!v2Check)) {
            cout << "\nAdditional objects for the operation: " << v2 << '\n';
            textTmp << "\nAdditional objects for the operation: " << v2 << '\n';
            v2.setX(0);
            v2.setY(0);
            v2.setZ(0);
        }
        else
            cout << '\n';
    } while (option != 0);

}

Vector createNewVector(const char* inputArr) {

    int option = 0;
    bool ckr = false;
    char* optTmp = new char[100];
    char fi = '/';
    char fi2 = '/';

    do {

        cout << "How would you like to initialize the new vector:\n";
        cout << "1. With two points\n2. With three variables\n";
        if (globStream == 2) {
            fi = inputArr[glob];
            fi2 = inputArr[glob+1];
            glob++;
            glob++;
        } else {
            cin >> optTmp;
        }

        if ((strcmp(optTmp, "1") == 0) || (fi == '1' && fi2 == '\'')) {
            option = 1;
            ckr = true;
        }
        else if ((strcmp(optTmp, "2") == 0) || (fi == '2' && fi2 == '\'')) {
            option = 2;
            ckr = true;
        }
        else {
            option = 0;
        }
        if (!ckr) {
            cout << "\nPlease enter a valid command (Press 1 or 2)!\n";
            exit(0);
        }
    } while (option != 1 && option != 2);

    if (option == 1) {
        Point p1 = createNewPoint(inputArr);
        Point p2 = createNewPoint(inputArr);

        return Vector(p1, p2);
    }
    else {

        double x, y, z;
        bool validation = false;

        cout << "Please enter values for a new Vector:\n";
        do {
            if (globStream == 2) {
                fi = inputArr[glob];
                glob++;
                x = (double) fi;
                x = x - 48;
            } else {
                cout << "x = ";
                cin >> x;
            }
            if (cin.good()) {
                validation = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a number!" << endl;
                validation = false;
            }
        } while (!validation);

        validation = false;

        do {
            if (globStream == 2) {
                fi = inputArr[glob];
                glob++;
                y = (double) fi;
                y = y - 48;
            } else {
                cout << "y = ";
                cin >> y;
            }
            if (cin.good()) {
                validation = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a number!" << endl;
                validation = false;
            }
        } while (!validation);

        validation = false;

        do {
            if (globStream == 2) {
                fi = inputArr[glob];
                glob++;
                z = (double) fi;
                z = z - 48;
            } else {
                cout << "z = ";
                cin >> z;
            }
            if (cin.good()) {
                validation = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a number!" << endl;
                validation = false;
            }
        } while (!validation);

        return Vector(x, y, z);
    }
}

//For class Line:

void menuLine(int stream,  std::fstream& userOutput, std::fstream& textTmp, const char* inputArr){
    int option = -1;
    bool ckr = false;
    char *optTmp = new char[100];
    char fi = '/';
    char fi2 = '/';

    bool validation = false;

    Line l1 = createNewLine(inputArr);
    Line l2;
    Point p;


    cout << "\nLine\n" << l1;
    textTmp << "\nLine\n" << l1;

    do {
        do {

            cout << "\nPlease choose an operation with your Vector:\n";
            cout << "1. Find line direction.\n";
            cout << "2. Find the normal vector of the line.\n";
            cout << "3. Find the angle between two lines.\n";
            cout << "4. Check if a point lies on the line.\n";
            cout << "5. Check if two lines are parallel.\n";
            cout << "6. Check if two lines coincide.\n";
            cout << "7. Check if two lines intersect.\n";
            cout << "8. Check if two lines are crossed.\n";
            cout << "9. Check if two lines are perpendicular.\n";
            cout << "0. Return - Select a new object.\n";

            if (globStream == 2) {
                fi = inputArr[glob];
                fi2 = inputArr[glob+1];
                glob++;
                glob++;
            } else {
                cin >> optTmp;
            }

            if ((strcmp(optTmp, "1") == 0) || (fi == '1' && fi2 == '\'')) {
                option = 1;
                ckr = true;
            } else if ((strcmp(optTmp, "2") == 0) || (fi == '2' && fi2 == '\'')) {
                option = 2;
                ckr = true;
            } else if ((strcmp(optTmp, "3") == 0) || (fi == '3' && fi2 == '\'')) {
                option = 3;
                l2 = createNewLine(inputArr);
                ckr = true;
            } else if ((strcmp(optTmp, "4") == 0) || (fi == '4' && fi2 == '\'')) {
                option = 4;
                p = createNewPoint(inputArr);
                ckr = true;
            } else if ((strcmp(optTmp, "5") == 0) || (fi == '5' && fi2 == '\'')) {
                option = 5;
                ckr = true;
            } else if ((strcmp(optTmp, "6") == 0) || (fi == '6' && fi2 == '\'')) {
                option = 6;
                l2 = createNewLine(inputArr);
                ckr = true;
            } else if ((strcmp(optTmp, "7") == 0) || (fi == '7' && fi2 == '\'')) {
                option = 7;
                l2 = createNewLine(inputArr);
                ckr = true;
            } else if ((strcmp(optTmp, "8") == 0) || (fi == '8' && fi2 == '\'')) {
                option = 8;
                l2 = createNewLine(inputArr);
                ckr = true;
            } else if ((strcmp(optTmp, "9") == 0) || (fi == '9' && fi2 == '\'')) {
                option = 9;
                l2 = createNewLine(inputArr);
                ckr = true;
            } else if ((strcmp(optTmp, "0") == 0) || (fi == '0' && fi2 == '\'')) {
                option = 0;
                ckr = true;
            } else
                option = -1;

            if (!ckr) {
                cout << "\nPlease enter a valid command (Press 0 to 9)!\n";
                if (globStream == 2) {
                    exit(0);
                }
            }
        } while (option < 0 || option > 11);


        switch (option) {
            case 1:
                cout << "Direction: " << l1.findLineDirection() << '\n';
                textTmp << "Direction: " << l1.findLineDirection() << '\n';
                break;
            case 2:
                cout << "Normal vector = " << l1.findNormalVector() << '\n';
                textTmp << "Normal vector = " << l1.findNormalVector() << '\n';
                break;
            case 3:
                cout << Line::findAngleBetweenTwoLines(l1, l2) << '\n';
                textTmp << "Angle = " << Line::findAngleBetweenTwoLines(l1, l2) << '\n';
                break;
            case 4:
                cout << "Check if a point lies on the line.\n";
                textTmp << "Check if a point lies on the line.\n";
                if (p + l1) {
                    cout << "True\n";
                    textTmp << "True\n";
                }
                else {
                    cout << "False\n";
                    textTmp << "False\n";
                }
                break;
            case 5:
                l2 = createNewLine(inputArr);
                cout << "Is " << l1 << " parallel to " << l2 << ":\n";
                textTmp << "Is " << l1 << " parallel to " << l2 << "\n";
                if (l1||l2) {
                    cout << "True\n";
                    textTmp << "True\n";
                }
                else {
                    cout << "False\n";
                    textTmp << "False\n";
                }
                break;
            case 6:
                cout << "Does " << l1 << " and " << l2 << " coincide:\n";
                textTmp << "Does " << l1 << " and " << l2 << " coincide:\n";
                if (l1==l2) {
                    cout << "True\n";
                    textTmp << "True\n";
                }
                else {
                    cout << "False\n";
                    textTmp << "False\n";
                }
                break;
            case 7:
                cout << "Does Line" << l1 << " and Line" << l2 << " intersect:\n";
                textTmp << "Does Line" << l1 << " and Line" << l2 << " intersect:\n";
                if (l1&&l2) {
                    cout << "True\n";
                    textTmp << "True\n";
                }
                else {
                    cout << "False\n";
                    textTmp << "False\n";
                }
                break;
            case 8:
                cout << "Are " << l1 << " and " << l2 << " crossed:\n";
                textTmp << "Are " << l1 << " and " << l2 << " crossed:\n";
                if (l1!=l2) {
                    cout << "True\n";
                    textTmp << "True\n";
                }
                else {
                    cout << "False\n";
                    textTmp << "False\n";
                }
                break;
            case 9:
                cout << "Are " << l1 << " and " << l2 << " perpendicular:\n";
                textTmp << "Are " << l1 << " and " << l2 << " perpendicular:\n";
                if (l1|l2) {
                    cout << "True\n";
                    textTmp << "True\n";
                }
                else {
                    cout << "False\n";
                    textTmp << "False\n";
                }
                break;
        }

        bool v2Check = l2.getLinePoint1().getX() == 0 && l2.getLinePoint1().getY() == 0
                       && l2.getLinePoint1().getZ() == 0 && l2.getLinePoint2().getX() == 0
                       && l2.getLinePoint2().getY() == 0 && l2.getLinePoint2().getZ() == 0;
        bool v3Check = p.getX() == 0 && p.getY() == 0 && p.getZ() == 0;

        if ((!v2Check) && (!v3Check)) {
            cout << "\nAdditional objects for the operation: " << l2 << '\t' << p << '\n';
            textTmp << "\nAdditional objects for the operation: " << l2 << '\t' << p << '\n';
            l2.setX(0);
            l2.setY(0);
            l2.setZ(0);
            p.setX(0);
            p.setY(0);
            p.setZ(0);
        }
        else if (v2Check && (!v3Check)) {
            cout << "\nAdditional objects for the operation: " << p << '\n';
            textTmp << "\nAdditional objects for the operation: " << p << '\n';
            p.setX(0);
            p.setY(0);
            p.setZ(0);
        }
        else if (v3Check && (!v2Check)) {
            cout << "\nAdditional objects for the operation: " << l2 << '\n';
            textTmp << "\nAdditional objects for the operation: " << l2 << '\n';
            l2.setX(0);
            l2.setY(0);
            l2.setZ(0);
        }
        else
            cout << '\n';
    } while (option != 0);

}

Line createNewLine(const char* inputArr) {
    int option = 0;
    bool ckr = false;
    char* optTmp = new char[100];
    char fi = '/';
    char fi2 = '/';

    do {

        cout << "How would you like to initialize the new line:\n";
        cout << "1. With two points\n2. With a point and a vector\n";
        if (globStream == 2) {
            fi = inputArr[glob];
            fi2 = inputArr[glob+1];
            glob++;
            glob++;
        } else {
            cin >> optTmp;
        }

        if ((strcmp(optTmp, "1") == 0) || (fi == '1' && fi2 == '\'')) {
            option = 1;
            ckr = true;
        }
        else if ((strcmp(optTmp, "2") == 0) || (fi == '2' && fi2 == '\'')) {
            option = 2;
            ckr = true;
        }
        else {
            option = -1;
        }
        if (!ckr) {
            cout << "\nPlease enter a valid command (Press 1 or 2)!\n";
            exit(0);
        }
    } while (option != 1 && option != 2);

    if (option == 1) {
        Point p1 = createNewPoint(inputArr);
        Point p2 = createNewPoint(inputArr);

        return Line(p1, p2);
    }
    else {

        double x, y, z;
        bool validation = false;

        Point pv = createNewPoint(inputArr);

        cout << "Please enter values for the Vector:\n";
        do {
            if (globStream == 2) {
                fi = inputArr[glob];
                glob++;
                x = (double) fi;
                x = x - 48;
            } else {
                cout << "x = ";
                cin >> x;
            }
            if (cin.good()) {
                validation = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a number!" << endl;
                validation = false;
            }
        } while (!validation);

        validation = false;

        do {
            if (globStream == 2) {
                fi = inputArr[glob];
                glob++;
                y = (double) fi;
                y = y - 48;
            } else {
                cout << "y = ";
                cin >> y;
            }
            if (cin.good()) {
                validation = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a number!" << endl;
                validation = false;
            }
        } while (!validation);

        validation = false;

        do {
            if (globStream == 2) {
                fi = inputArr[glob];
                glob++;
                z = (double) fi;
                z = z - 48;
            } else {
                cout << "z = ";
                cin >> z;
            }
            if (cin.good()) {
                validation = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a number!" << endl;
                validation = false;
            }
        } while (!validation);

        Vector v1(x, y, z);

        return Line(pv, v1);
    }
}

//For class Segment:

void menuSegment(int stream, std::fstream& userOutput, std::fstream& textTmp, const char* inputArr)
{
    int option = -1;
    bool ckr = false;
    char* optTmp = new char[100];
    char fi = '/';
    char fi2 = '/';

    bool validation = false;

    Segment segment;
    Point p;//if user wants to check if a points lays on segment

    cout << "\nSegment\n" << segment;
    textTmp << "\nSegment\n" << segment;

    segment = createNewSegment(inputArr);
    do
    {
        do
        {
            cout << "\nSelect an operation from a segment-specific array of operations for the newly created Segment:\n";
            cout << "1.Find length of segment.\n";
            cout << "2.Find the middle of a segment.\n";
            cout << "3.Check if a point is laying on the segment.\n";
            cout << "0. Return.\n";
            if (globStream == 2) {
                fi = inputArr[glob];
                fi2 = inputArr[glob+1];
                glob++;
                glob++;
            } else {
                cin >> optTmp;
            }

            if ((strcmp(optTmp, "1") == 0) || (fi == '1' && fi2 == '\'')) {
                option = 1;
                ckr = true;
            }
            else if ((strcmp(optTmp, "2") == 0) || (fi == '2' && fi2 == '\'')) {
                option = 2;
                ckr = true;
            }
            else if ((strcmp(optTmp, "3") == 0) || (fi == '3' && fi2 == '\'')) {
                option = 3;
                ckr = true;
            }
            else if ((strcmp(optTmp, "0") == 0) || (fi == '0' && fi2 == '\'')) {
                option = 0;
                ckr = true;
            }

            else
            {
                option = -1;
            }

            if (!ckr)
            {
                cout << "\nPlease enter a valid command (Press 0 to 3)!\n";
                if (globStream == 2) {
                    exit(0);
                }
            }
        } while (option < 0 || option > 3);

        switch (option)
        {
            case 0:
                return;
            case 1:
                cout << "Length of segment = " << segment.getLength() << '\n';
                textTmp << "Length of segment = " << segment.getLength() << '\n';
                break;
            case 2:
                cout << "Coordinates of middle point of segment " << segment.findMiddle() << '\n';
                textTmp << "Coordinates of middle point of segment " << segment.findMiddle() << '\n';
                break;
            case 3:
                cout << "Initialize a point and check if it is laying on segment.\n";
                textTmp << "Initialize a point and check if it is laying on segment.\n";
                p = createNewPoint(inputArr);
                if (segment == p)
                {
                    cout << "Point is laying on segment.\n";
                    textTmp << "Point is laying on segment.\n";
                }
                else
                {
                    cout << "Point is not laying on segment.\n";
                    textTmp << "Point is not laying on segment.\n";
                }
                break;
            default:
                break;
        }

        bool isPoint_init;
        if (p.getX() == 0 && p.getY() == 0 && p.getZ() == 0)
        {
            isPoint_init = 0;
        }
        else
        {
            isPoint_init = 1;
            cout << "Additional object used for the operation: " << p << '\n';
            textTmp << "Additional object used for the operation: " << p << '\n';
        }


    } while (option != 0);
}

Segment createNewSegment(const char* inputArr)
{
    int option = 0;
    bool ckr = false;
    char* optTmp = new char[100];
    char fi = '/';
    char fi2 = '/';

    do {

        cout << "How would you like to initialize the new segment:\n";
        cout << "1. With two points\n2. With a point and a vector\n";
        if (globStream == 2) {
            fi = inputArr[glob];
            fi2 = inputArr[glob+1];
            glob++;
            glob++;
        } else {
            cin >> optTmp;
        }

        if ((strcmp(optTmp, "1") == 0) || (fi == '1' && fi2 == '\'')) {
            option = 1;
            ckr = true;
        }
        else if ((strcmp(optTmp, "2") == 0) || (fi == '2' && fi2 == '\'')) {
            option = 2;
            ckr = true;
        }
        else {
            option = -1;
        }
        if (!ckr) {
            cout << "\nPlease enter a valid command (Press 1 or 2)!\n";
            exit(0);
        }
    } while (option != 1 && option != 2);

    if (option == 1) {
        Point p1 = createNewPoint(inputArr);
        Point p2 = createNewPoint(inputArr);

        Segment a(p1, p2);
        return a;
    }
    else {

        double x, y, z;
        bool validation = false;

        Point pv = createNewPoint(inputArr);

        cout << "Please enter values for the slope of the segment:\n";
        do {
            if (globStream == 2) {
                fi = inputArr[glob];
                glob++;
                x = (double) fi;
                x = x - 48;
            } else {
                cout << "x = ";
                cin >> x;
            }
            if (cin.good()) {
                validation = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a number!" << endl;
                validation = false;
            }
        } while (!validation);

        validation = false;

        do {
            if (globStream == 2) {
                fi = inputArr[glob];
                glob++;
                y = (double) fi;
                y = y - 48;
            } else {
                cout << "y = ";
                cin >> y;
            }
            if (cin.good()) {
                validation = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a number!" << endl;
                validation = false;
            }
        } while (!validation);

        validation = false;

        do {
            if (globStream == 2) {
                fi = inputArr[glob];
                glob++;
                z = (double) fi;
                z = z - 48;
            } else {
                cout << "z = ";
                cin >> z;
            }
            if (cin.good()) {
                validation = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a number!" << endl;
                validation = false;
            }
        } while (!validation);

        Vector v1(x, y, z);

        Segment a(pv, v1);
        return a;
    }

}

//For class Triangle:

void menuTriangle(int stream, std::fstream& userOutput, std::fstream& textTmp, const char* inputArr)
{
    cout << "A Triangle can only be initialized with three points.\n";

    int option = -1;
    bool ckr = false;
    char* optTmp = new char[100];
    char fi = '/';
    char fi2 = '/';
    char fi3 = '/';

    Triangle triangle;

    try
    {
        triangle = createNewTriangle(inputArr);
    }
    catch (EqualPointException)
    {
        cout << "Can't initialize triangle with overlapping points, please try again.\n";
        menuTriangle(stream, userOutput, textTmp, inputArr);
    }
    cout << "Triangle initialized.\n";

    bool validation = false;

    Point p;

    cout << "\nTriangle\n" << triangle << '\n';
    textTmp << "\nTriangle\n" << triangle << '\n';

    do
    {
        do
        {
            cout << "\nPlease choose an operation with your Triangle:\n";
            cout << "1. Check if Triangle is isosceles.\n";
            cout << "2. Check if Triangle is equilateral.\n";
            cout << "3. Check if Triangle's angles are acute.\n";
            cout << "4. Check if Triangle's angles are right.\n";
            cout << "5. Check if Triangles's angles are obtuse.\n";
            cout << "6. Calculate Area of Triangle.\n";
            cout << "7. Get Perimeter of Triangle.\n";
            cout << "8. Get Centroid of Triangle.\n";
            cout << "9. Check if a Point is inside the Triangle.\n";
            cout << "10. Check if a Point is outside the Triangle.\n";
            cout << "11. Check if a Point is laying on the Perimeter of the Triangle.\n";
            cout << "0. Return\n";
            if (globStream == 2) {
                fi = inputArr[glob];
                fi2 = inputArr[glob+1];
                fi3 = inputArr[glob+2];
                if (fi3 == '\'')
                    glob++;
                glob++;
                glob++;
            } else {
                cin >> optTmp;
            }

            if ((strcmp(optTmp, "1") == 0) || (fi == '1' && fi2 == '\'')) {
                option = 1;
                ckr = true;
            }
            else if ((strcmp(optTmp, "2") == 0) || (fi == '2' && fi2 == '\'')) {
                option = 2;
                ckr = true;
            }
            else if ((strcmp(optTmp, "3") == 0) || (fi == '3' && fi2 == '\'')) {
                option = 3;
                ckr = true;
            }
            else if ((strcmp(optTmp, "4") == 0) || (fi == '4' && fi2 == '\'')) {
                option = 4;
                ckr = true;
            }
            else if ((strcmp(optTmp, "5") == 0) || (fi == '5' && fi2 == '\'')) {
                option = 5;
                ckr = true;
            }
            else if ((strcmp(optTmp, "6") == 0) || (fi == '6' && fi2 == '\'')) {
                option = 6;
                ckr = true;
            }
            else if ((strcmp(optTmp, "7") == 0) || (fi == '7' && fi2 == '\'')) {
                option = 7;
                ckr = true;
            }
            else if ((strcmp(optTmp, "8") == 0) || (fi == '8' && fi2 == '\'')) {
                option = 8;
                ckr = true;
            }
            else if ((strcmp(optTmp, "9") == 0) || (fi == '9' && fi2 == '\'')) {
                option = 9;
                ckr = true;
            }
            else if ((strcmp(optTmp, "10") == 0) || (fi == '1' && fi2 == '0' && fi3 == '\'')) {
                option = 10;
                ckr = true;
            }
            else if ((strcmp(optTmp, "11") == 0) || (fi == '1' && fi2 == '1' && fi3 == '\'')) {
                option = 11;
                ckr = true;
            }
            else if ((strcmp(optTmp, "0") == 0) || (fi == '0' && fi2 == '\'')) {
                option = 0;
                ckr = true;
            }
            else
                option = -1;

            if (!ckr) {
                cout << "\nPlease enter a valid command (Press 0 to 11)!\n";
                if (globStream == 2) {
                    exit(0);
                }
            }

        } while (option < 0 || option > 11);

        //REMOVE COMMENTS WHEN OPERATORS <,>,== FOR TRIANGLE ARE OVERLOADED
        //ALSO REMOVE ON IF STREAM == 2
        switch (option)
        {
            case 1:
                if (triangle.isIsosceles())
                {
                    cout << "Triangle is isosceles.\n";
                    textTmp << "Triangle is isosceles.\n";
                }
                else {
                    cout << "Triangle is not isoceles.\n";
                    textTmp << "Triangle is not isoceles.\n";
                }
                break;
            case 2:
                if (triangle.isEquilateral())
                {
                    cout << "Triangle is equilateral.\n";
                    textTmp << "Triangle is equilateral.\n";
                }
                else {
                    cout << "Triangle is not equilateral.\n";
                }
                break;
            case 3:
                if (triangle.isAcuteAngled())
                {
                    cout << "Triangle is acute angled.\n";
                    textTmp << "Triangle is acute angled.\n";
                }
                else {
                    cout << "Triangle is not acute angled.\n";
                    textTmp << "Triangle is not acute angled.\n";
                }
                break;
            case 4:
                if (triangle.isRightAngled())
                {
                    cout << "Triagle is right angled.\n";
                    textTmp << "Triagle is right angled.\n";
                }
                else
                {
                    cout << "Triangle is not right angled.\n";
                    textTmp << "Triangle is not right angled.\n";
                }
                break;
            case 5:
                if (triangle.isObtuse())
                {
                    cout << "Triangle is obtuse.\n";
                    textTmp << "Triangle is obtuse.\n";
                }
                else
                {
                    cout << "Triangle is not obtuse.\n";
                    textTmp << "Triangle is obtuse.\n";
                }
                break;
            case 6:
                cout << "Area of Triangle S = " << triangle.getArea() << "\n";
                textTmp << "Area of Triangle S = " << triangle.getArea() << "\n";
                break;
            case 7:
                cout << "Perimter of Triangle P = " << triangle.getPerimeter() << "\n";
                textTmp << "Perimter of Triangle P = " << triangle.getPerimeter() << "\n";
                break;
            case 8:
                cout << "Centroid of Triangle M = " << triangle.getCentroid() << "\n";
                textTmp << "Centroid of Triangle M = " << triangle.getCentroid() << "\n";
                break;
            case 9:
                p = createNewPoint(inputArr);
                if (p < triangle)
                {
                    cout << "Point P is inside of Triangle.\n";
                    textTmp << "Point P is inside of Triangle.\n";
                }
                else
                {
                    cout << "Point P is not inside of Triangle.\n";
                    textTmp << "Point P is not inside of Triangle.\n";
                }
                break;
            case 10:
                p = createNewPoint(inputArr);
                if (p > triangle)
                {
                    cout << "Point P is outside of Triangle.\n";
                    textTmp << "Point P is outside of Triangle.\n";
                }
                else
                {
                    cout << "Point P is not outside of Triangle.\n";
                    textTmp << "Point P is outside of Triangle.\n";
                }
                break;
            case 11:
                p = createNewPoint(inputArr);
                if (triangle == p)
                {
                    cout << "Point P is laying on Perimeter of Triangle.\n";
                    textTmp << "Point P is laying on Perimeter of Triangle.\n";
                }
                else
                {
                    cout << "Point P is not laying on Perimeter of Triangle.\n";
                    textTmp << "Point P is not laying on Perimeter of Triangle.\n";
                }
                break;
        }
        if (!(p.getX() == 0 && p.getY() == 0 && p.getY() == 0))
        {
            cout << "\nAdditional objects for the operation: " << p << '\n';
            textTmp << "\nAdditional objects for the operation: " << p << '\n';
        }
    } while (option != 0);

}

Triangle createNewTriangle(const char* inputArr)
{
    Point A = createNewPoint(inputArr);
    Point B = createNewPoint(inputArr);
    Point C = createNewPoint(inputArr);

    Triangle tr(A, B, C);
    return tr;

}

//For class Tetrahedron:

void menuTetrahedron(int stream, std::fstream& userOutput, std::fstream& textTmp, const char* inputArr) {
    int option = -1;
    bool ckr = false;
    char *optTmp = new char[100];
    char fi = '/';
    char fi2 = '/';

    bool validation = false;

    Tetrahedron t1 = createNewTetrahedron(inputArr);
    Point p1;

    cout << "\nTetrahedron\n" << t1;
    textTmp << "\nTetrahedron\n" << t1;


    do {
        do {

            cout << "\nPlease choose an operation with your Vector:\n";
            cout << "1. Check if the tetrahedron is regular (all edges are equal).\n";
            cout << "2. Check if it is orthogonal (every two opposite edges are perpendicular).\n";
            cout << "3. Find the surrounding surface.\n";
            cout << "4. Find the volume.\n";
            cout << "5. Check if a Point is inside the Tetrahedron.\n";
            cout << "6. Check if a Point is outside the Tetrahedron.\n";
            cout << "7. Check if a Point is laying on the Perimeter of the Tetrahedron.\n";
            cout << "0. Return - Select a new object.\n";
            if (globStream == 2) {
                fi = inputArr[glob];
                fi2 = inputArr[glob+1];
                glob++;
                glob++;
            } else {
                cin >> optTmp;
            }

            if ((strcmp(optTmp, "1") == 0) || (fi == '1' && fi2 == '\'')) {
                option = 1;
                ckr = true;
            } else if ((strcmp(optTmp, "2") == 0) || (fi == '2' && fi2 == '\'')) {
                option = 2;
                ckr = true;
            } else if ((strcmp(optTmp, "3") == 0) || (fi == '3' && fi2 == '\'')) {
                option = 3;
                ckr = true;
            } else if ((strcmp(optTmp, "4") == 0) || (fi == '4' && fi2 == '\'')) {
                option = 4;
                ckr = true;
            } else if ((strcmp(optTmp, "5") == 0) || (fi == '5' && fi2 == '\'')) {
                option = 5;
                ckr = true;
            } else if ((strcmp(optTmp, "6") == 0) || (fi == '6' && fi2 == '\'')) {
                option = 6;
                ckr = true;
            } else if ((strcmp(optTmp, "7") == 0) || (fi == '7' && fi2 == '\'')) {
                option = 7;
                ckr = true;
            } else if (strcmp(optTmp, "0") == 0 || fi == '0') {
                option = 0;
                ckr = true;
            } else
                option = -1;

            if (!ckr) {
                cout << "\nPlease enter a valid command (Press 0 to 7)!\n";
                if (globStream == 2) {
                    exit(0);
                }
            }
        } while (option < 0 || option > 7);


        switch (option) {
            case 1:
                cout << "Is it regular:\n";
                textTmp << "Is it regular:\n";
                if (t1.IsRegular()) {
                    cout << "True\n";
                    textTmp << "True\n";
                }
                else {
                    cout << "False\n";
                    textTmp << "False\n";
                }
                break;
            case 2:
                cout << "Is it orthogonal:\n";
                textTmp << "Is it orthogonal:\n";
                if (t1.IsOrthogonal()) {
                    cout << "True\n";
                    textTmp << "True\n";
                }
                else {
                    cout << "False\n";
                    textTmp << "False\n";
                }
                break;
            case 3:
                cout << "Surface = " << t1.getSurface() << '\n';
                textTmp << "Surface = " << t1.getSurface() << '\n';
                break;
            case 4:
                cout << "Volume = " << t1.getVolume() << '\n';
                textTmp << "Volume = " << t1.getVolume() << '\n';
                break;
            case 5:
                p1 = createNewPoint(inputArr);
                if (p1 < t1)
                {
                    cout << "Point P is inside of Tetrahedron.\n";
                    textTmp << "Point P is inside of Tetrahedron.\n";
                }
                else
                {
                    cout << "Point P is not inside of Tetrahedron.\n";
                    textTmp << "Point P is not inside of Tetrahedron.\n";
                }
                break;
            case 6:
                p1 = createNewPoint(inputArr);
                if (p1 > t1)
                {
                    cout << "Point P is outside of Tetrahedron.\n";
                    textTmp << "Point P is outside of Tetrahedron.\n";
                }
                else
                {
                    cout << "Point P is not outside of Tetrahedron.\n";
                    textTmp << "Point P is outside of Tetrahedron.\n";
                }
                break;
            case 7:
                p1 = createNewPoint(inputArr);
                if (t1 == p1)
                {
                    cout << "Point P is laying on Perimeter of Tetrahedron.\n";
                    textTmp << "Point P is laying on Perimeter of Tetrahedron.\n";
                }
                else
                {
                    cout << "Point P is not laying on Perimeter of Tetrahedron.\n";
                    textTmp << "Point P is not laying on Perimeter of Tetrahedron.\n";
                }
                break;
        }

        bool v2Check = p1.getX() == 0 && p1.getY() == 0 && p1.getZ() == 0;

        if (!v2Check) {
            cout << "\nAdditional objects for the operation: " << p1 << '\n';
            textTmp << "\nAdditional objects for the operation: " << p1 << '\n';
        } else
            cout << '\n';
    } while (option != 0);

}

Tetrahedron createNewTetrahedron(const char* inputArr) {
    int option = 0;
    bool ckr = false;
    char* optTmp = new char[100];

    Point p1 = createNewPoint(inputArr);
    Point p2 = createNewPoint(inputArr);
    Point p3 = createNewPoint(inputArr);
    Point p4 = createNewPoint(inputArr);

    return Tetrahedron(p1, p2, p3, p4);

}
