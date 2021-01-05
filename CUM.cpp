/*
 * Common User Manager
 * 
 * Copyright 2020 Steve Wang <47wang@gmail.com>
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
#include <vector>

using namespace std;

ifstream namein("name.list");
ofstream nout("name.list", ios::app);

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
    cout << "Common User Manager 1.0" << endl;
    cout << "Copyright 2020 Steve Wang <47wang@gmail.com>\nThis program is free software; you can redistribute it and/or modify\nit under the terms of the GNU General Public License as published by\nthe Free Software Foundation; either version 3 of the License, or\n(at your option) any later version.\n\nThis program is distributed in the hope that it will be useful,\nbut WITHOUT ANY WARRANTY; without even the implied warranty of\nMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\nGNU General Public License for more details.\n\nYou should have received a copy of the GNU General Public License\nalong with this program; if not, see <http://www.gnu.org/licenses/>.\n\n\n";
    while(1)
    {
        cout << "CUM 1.0 > ";
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
