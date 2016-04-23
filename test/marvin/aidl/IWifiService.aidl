
package aidl;

interface IWifiService {
    void SetEnabled(boolean enabled);
    void SendCommand(int command, int arg1, int arg2);
}
