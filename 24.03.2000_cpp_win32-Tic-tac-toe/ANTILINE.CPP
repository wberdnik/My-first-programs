//wberdnik@gmail.com
//---------------------------------------------------------------------------
#include <condefs.h>
#include <windows.h>
#pragma hdrstop
USERC("antiline.rc");
BOOL CALLBACK DialogProc(HWND  hwndDlg,UINT  uMsg,
    WPARAM  wParam,LPARAM  lParam);

//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{

    while(DialogBox(hInstance,"MainForm",NULL,(DLGPROC)DialogProc)!=100);
    return 0;
}
//---------------------------------------------------------------------------


BOOL CALLBACK DialogProc(

    HWND  hwndDlg,	// handle of dialog box
    UINT  uMsg,	// message
    WPARAM  wParam,	// first message parameter
    LPARAM  lParam 	// second message parameter
   ){

   HWND CI;
   static char mass[9];
   char vector[9];
   char sym;
   char max;
   switch(uMsg){
   case WM_COMMAND:
            switch(wParam){
             case 101:
             case 102:
             case 103:
             case 104:
             case 105:
             case 106:
             case 107:
             case 108:
             case 109:
                        CI=GetDlgItem(hwndDlg,wParam);
                        if (mass[wParam-101]==0){
                            mass[wParam-101]=1;
                            SetWindowText(CI,"X");
                            if ((mass[0]+mass[1]+mass[2]==3)||
                                (mass[3]+mass[4]+mass[5]==3)||
                                (mass[6]+mass[7]+mass[8]==3)||
                                (mass[0]+mass[3]+mass[6]==3)||
                                (mass[1]+mass[4]+mass[7]==3)||
                                (mass[0]+mass[4]+mass[8]==3)||
                                (mass[2]+mass[4]+mass[6]==3)||
                                (mass[2]+mass[5]+mass[8]==3)) {
                                MessageBox(hwndDlg,"You win"," Победа !!",MB_OK);
                                EndDialog(hwndDlg,11);
                                return TRUE;       }

                                sym=0;
                                for(int i=0;i<9;i++)
                                    if (mass[i]==0) {
                                        vector[i]=0;
                                        sym=1;       }
                                    else
                                        vector[i]=-100;
                          if (sym==0) {
                                MessageBox(hwndDlg,"Ничья"," Ничья",MB_OK);
                                EndDialog(hwndDlg,11);
                                return TRUE;
                                  }



                                vector[4]=vector[4]+5;
                                vector[0]=vector[0]+1;
                                vector[2]=vector[2]+1;
                                vector[6]=vector[6]+1;
                                vector[8]=vector[8]+1;

                               if ( (mass[1]+mass[2]==-2)||
                                    (mass[3]+mass[6]==-2)||
                                    (mass[4]+mass[8]==-2))
                                            vector[0]=vector[0]+10;
                               if ( (mass[3]+mass[6]==2)||
                                    (mass[1]+mass[2]==2)||
                                    (mass[4]+mass[8]==2))
                                            vector[0]=vector[0]+8;

                               if ((mass[0]+mass[2]==-2)||
                                   (mass[4]+mass[7]==-2))
                                            vector[1]=vector[1]+10;
                               if ((mass[0]+mass[2]==2)||
                                   (mass[4]+mass[7]==2))
                                            vector[1]=vector[1]+8;


                               if ((mass[0]+mass[1]==-2)||
                                   (mass[4]+mass[6]==-2)||
                                   (mass[5]+mass[8]==-2))
                                            vector[2]=vector[2]+10;
                               if ((mass[0]+mass[1]==2)||
                                   (mass[4]+mass[6]==2)||
                                   (mass[5]+mass[8]==2))
                                            vector[2]=vector[2]+8;

                               if ((mass[4]+mass[5]==-2)||
                                    (mass[0]+mass[6]==-2))
                                            vector[3]=vector[3]+10;
                               if ((mass[4]+mass[5]==2)||
                                   (mass[0]+mass[6]==2))
                                            vector[3]=vector[3]+8;

                               if ((mass[3]+mass[5]==-2)||
                                   (mass[0]+mass[8]==-2)||
                                   (mass[2]+mass[6]==-2)||
                                   (mass[1]+mass[7]==-2))
                                            vector[4]=vector[4]+10;
                               if ((mass[1]+mass[7]==2)||
                                   (mass[0]+mass[8]==2)||
                                   (mass[2]+mass[6]==2)||
                                   (mass[1]+mass[7]==2))
                                            vector[4]=vector[4]+8;


                               if ((mass[3]+mass[4]==-2)||
                                   (mass[2]+mass[8]==-2))
                                            vector[5]=vector[5]+10;
                               if ((mass[3]+mass[4]==2)||
                                   (mass[2]+mass[8]==2))
                                            vector[5]=vector[5]+8;

                               if ((mass[7]+mass[8]==-2)||
                                   (mass[4]+mass[2]==-2)||
                                   (mass[0]+mass[3]==-2))
                                            vector[6]=vector[6]+10;
                               if ((mass[7]+mass[8]==2)||
                                   (mass[4]+mass[2]==2)||
                                    (mass[0]+mass[3]==2))
                                            vector[6]=vector[6]+8;

                               if ((mass[6]+mass[8]==-2)||
                                   (mass[1]+mass[4]==-2))
                                            vector[7]=vector[7]+10;
                               if ((mass[6]+mass[8]==2)||
                                    (mass[1]+mass[4]==2))
                                            vector[7]=vector[7]+8;

                               if ((mass[6]+mass[7]==-2)||
                                   (mass[4]+mass[0]==-2)||
                                   (mass[2]+mass[5]==-2))
                                            vector[8]=vector[8]+10;
                               if ((mass[6]+mass[7]==2)||
                                   (mass[4]+mass[0]==2)||
                                   (mass[2]+mass[5]==2))
                                            vector[8]=vector[8]+8;

                               if (mass[1]+mass[3]==2){
                                            vector[0]=vector[0]+2;
                                            vector[3]=vector[3]+1;
                                            vector[6]=vector[6]+1;
                                                      }

                                if (mass[7]+mass[3]==2){
                                            vector[0]=vector[0]+1;
                                            vector[8]=vector[8]+1;
                                            vector[6]=vector[6]+2;
                                                      }

                                if (mass[1]+mass[5]==2){
                                            vector[0]=vector[0]+1;
                                            vector[8]=vector[8]+1;
                                            vector[2]=vector[2]+2;
                                                      }
                                if (mass[7]+mass[5]==2){
                                            vector[2]=vector[2]+1;
                                            vector[8]=vector[8]+2;
                                            vector[6]=vector[6]+1;
                                                      }





                            max=0;
                            for(int i=1;i<9;i++)
                                if (vector[max]<vector[i])
                                    max=i;

                            mass[max]=-1;
                            SetWindowText(GetDlgItem(hwndDlg,max+101),"O");



                            if ((mass[0]+mass[1]+mass[2]==-3)||
                                (mass[3]+mass[4]+mass[5]==-3)||
                                (mass[6]+mass[7]+mass[8]==-3)||
                                (mass[0]+mass[3]+mass[6]==-3)||
                                (mass[1]+mass[4]+mass[7]==-3)||
                                (mass[0]+mass[4]+mass[8]==-3)||
                                (mass[2]+mass[4]+mass[6]==-3)||
                                (mass[2]+mass[5]+mass[8]==-3)) {
                                MessageBox(hwndDlg,"I win"," Проиграл... ",MB_OK);
                                EndDialog(hwndDlg,11);
                                return TRUE;      }


                                                 }
                        return TRUE;

             case 110:
             EndDialog(hwndDlg,100);
            return TRUE;
            }
    case WM_PAINT:
                //MessageBox(NULL,"?","?",MB_APPLMODAL);
                return FALSE;
   case WM_INITDIALOG:
            for(int i=0;i<9;i++)mass[i]=0;
            return TRUE;
                     }
    return FALSE;
                    
   }