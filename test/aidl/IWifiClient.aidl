
package aidl;

import aidl.ScannedStation;
import aidl.ConfiguredStation;
import aidl.WifiInformation;

interface IWifiClient {
    oneway void State(int state, out int result);
    void ScanResults(in ScannedStation[] scandata);
    void ConfiguredStations(in ConfiguredStation[] configdata);
    void Information(in WifiInformation info);
    void Rssi(int rssi);
    void LinkSpeed(int link_speed);
}
