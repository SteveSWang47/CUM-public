/*
 * Common User Manager
 * 
 * Copyright 2020-2021 Steve Wang <47wang@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 * 
 */
 
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

ifstream namein("name.list");
ofstream nout("name.list", ios::app);

void badcom(char **argv)
{
    cerr << "Usage: " << argv[0] <<" [n|v|new|verify] [<name>] [<num>]";
}

int main(int argc, char **argv)
{
    vector<string> names;
    int nsum = 0;
    string uti;
    cout << "Reading database...  ";
    while(namein >> uti)
    {
        nsum++;
        names.push_back(uti);
    }
    cout << "Done." << endl;
    if(argc > 1)
    {
        string oper;
        oper = argv[1];
        if(argc == 2)
        {
            badcom(argv);
            return 1;
        }
        if(oper == "new" || oper == "n")
        {
            if(argc != 3)
            {
                badcom(argv);
                return 2147483647;
            }
            nout << argv[2] << '\n';
            cout << "The serial number of this user is " << nsum << endl;
            return 0;
        }
        if(oper == "verify" || oper == "v")
        {
            if(argc != 4)
            {
                badcom(argv);
                return 2147483647;
            }
            string ns = argv[3];
            stringstream sns(ns);
            int n;
            sns >> n;
            uti = argv[2];
            if(n < nsum && names[n] == uti)
            {
                cout << "[OK] The user verified successfully." << endl;
                return 0;
            }
            else
            {
                cout << "[!!] The user does not exist." << endl;
                return 0;
            }
        }
        badcom(argv);
        return 222;
    }
    cout << "Common User Manager 2.0" << endl;
    cout << "Copyright 2020-2021 Steve Wang <47wang@gmail.com>\nThis program is free software; you can redistribute it and/or modify\nit under the terms of the GNU General Public License as published by\nthe Free Software Foundation; either version 3 of the License, or\n(at your option) any later version.\n\nThis program is distributed in the hope that it will be useful,\nbut WITHOUT ANY WARRANTY; without even the implied warranty of\nMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\nGNU General Public License for more details.\n\nYou should have received a copy of the GNU General Public License\nalong with this program; if not, see <http://www.gnu.org/licenses/>.\n\n\n";
    while(1)
    {
        cout << "CUM 2.0 > ";
        cin >> uti;
        if(uti == "new" || uti == "n")
        {
            cin >> uti;
            nout << uti << '\n';
            names.push_back(uti);
            cout << "The serial number of this user is " << nsum << endl;
            nsum++;
        }
        else if(uti == "verify" || uti == "v")
        {
            int n;
            cin >> uti >> n;
            if(n < nsum && names[n] == uti)
            {
                cout << "[OK] The user verified successfully." << endl;
            }
            else
            {
                cout << "[!!] The user does not exist." << endl;
            }
        }
        else if(uti == "exit" || uti == "quit" || uti == "q")
        {
            break;
        }
        else
        {
            cerr << "[!!] Bad command." << endl;
        }
    }
    return 0;
}
