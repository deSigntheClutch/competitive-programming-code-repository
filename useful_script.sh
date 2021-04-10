# Create cpp&txt file with date
function crt() {
    for var in "$@"
    do
        suffix=`echo "${var##*.}"`
        echo $suffix
        if [[ $suffix == 'cpp' ]]; then
            touch $var;
            echo "// "`date` > $var; 
            echo "#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 10;

int T;

signed main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {

    }
    return 0;
}"           >> $var
        else
            touch $var;
        fi
    done
}
