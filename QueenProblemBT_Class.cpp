#include <iostream>
#include <vector>
using namespace std;


class Tabuleiro{

    private: 
        int n;//dimensão do vetor
        vector<vector<int>> tabuleiro;
    
    public:

        Tabuleiro(int N) : n(N), tabuleiro(N, vector<int>(N, 0)) {}

        bool seguro(int row, int col) const{
            if(tabuleiro[row][col] == -1)
                return false;
            return true;
        }

        void colocaRainha(int row, int col){

            tabuleiro[row][col] = 1;

            for (int i = 0; i < n; ++i){
                if( tabuleiro[i][col] == 0)
                    tabuleiro[i][col] = -1;
            }

            int i, j;

            for (i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
                if (tabuleiro[i][j] == 0) tabuleiro[i][j] = -1;

            for (i = row + 1, j = col + 1; i < n && j < n; ++i, ++j)
                if (tabuleiro[i][j] == 0) tabuleiro[i][j] = -1;

            for (i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
                if (tabuleiro[i][j] == 0) tabuleiro[i][j] = -1;

            for (i = row + 1, j = col - 1; i < n && j >= 0; ++i, --j)
                if (tabuleiro[i][j] == 0) tabuleiro[i][j] = -1;
            
        }

        void removerRainha(int row, int col){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(tabuleiro[i][j] != 1)
                        tabuleiro[i][j] = 0;
                }
            }
            tabuleiro[row][col] = 0;

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(tabuleiro[i][j] == 1)
                        colocaRainha(i,j);
                }
            }

        }

        bool resolve(int row){
            if(row == n)
                return true;
            for(int col = 0; col < n; col++){
                if(seguro(row, col)){
                    colocaRainha(row, col);
                    if(resolve(row+1))
                        return true;
                    removerRainha(row, col);
                }
            }
            return false;
        }
        
        vector<vector<int>> getTabuleiro() const {
            return tabuleiro;
        }
};
    


int main(){
    int dimensao;
    cout<< "Digite o tamanho N (ate 8): ";
    cin>> dimensao;

    Tabuleiro Tabuleiro(dimensao);
    if(Tabuleiro.resolve(0)) {
        cout<<"Problema resolvido!\n";
        auto sol = Tabuleiro.getTabuleiro();
        for (int i = 0; i < dimensao; ++i) {
            for (int j = 0; j < dimensao; ++j) {
                cout << (sol[i][j] == 1 ? 'Q' : '.') << ' ';
            }
            cout << '\n';
        }
    }
    else
        cout<<"Não foi impossível encontrar uma solução para N = " << dimensao << '\n';

    return 0;
}