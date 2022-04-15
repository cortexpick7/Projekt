for (int i = 1; i <= 18; i++) {
        switch(i) {
        case 1:
            {
                for (int j = 1; j <= 70; j++) {
                    cout << "-";
                }
                cout << endl;
                break;
            }
        case 6:
            {

                for (int p = 1; p <= 70; p++) {
                    if (p == 13) {
                        SetConsoleTextAttribute(h, 3);
                        cout << titul;
                        SetConsoleTextAttribute(h, 15);
                        p = titul.length() + p - 1;
                    } else if (p == 1 || p == 70) {
                        cout << "|";
                    } else {
                         cout << " ";
                    }
                }
                cout << endl;
                break;
            }
        case 9:
            {
                int middle = 35;
                int a = (middle - (adminStr.length()/2));
                for (int w = 1; w <= 70; w++) {
                    if (w == a) {
                        cout << adminStr;
                        w = adminStr.length() + a - 1;
                    } else if (w == 1 || w == 70) {
                        cout << "|";
                    } else {
                         cout << " ";
                    }
                }
                cout << endl;
                break;
            }
        case 11:
            {
                int middle = 35;
                int a = (middle - (bookShelfStr.length()/2));
                for (int w = 1; w <= 70; w++) {
                    if (w == a) {
                        cout << bookShelfStr;
                        w = bookShelfStr.length() + a - 1;
                    } else if (w == 1 || w == 70) {
                        cout << "|";
                    } else {
                         cout << " ";
                    }
                }
                cout << endl;
                break;
            }
        case 13:
            {
                int middle = 35;
                int a = (middle - (userPanel.length()/2));
                for (int w = 1; w <= 70; w++) {
                    if (w == a) {
                        cout << userPanel;
                        w = userPanel.length() + a - 1;
                    } else if (w == 1 || w == 70) {
                        cout << "|";
                    } else {
                         cout << " ";
                    }
                }
                cout << endl;
                break;
            }
        case 18:
            {
                for (int k = 1; k <= 70; k++) {
                    cout << "-";
                }
                cout << endl;
                break;
            }
        default:
            {
                for (int x = 1; x <= 70; x++) {
                    if (x == 1 || x == 70) {
                        cout << "|";
                    } else {
                        cout << " ";
                    }
                }
                cout << endl;
                break;
            }
        }
    }
