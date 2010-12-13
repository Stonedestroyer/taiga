/*
** Taiga, a lightweight client for MyAnimeList
** Copyright (C) 2010, Eren Okka
** 
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
** 
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "std.h"
#include "announce.h"
#include "common.h"
#include "dlg/dlg_main.h"
#include "recognition.h"
#include "resource.h"
#include "settings.h"
#include "string.h"
#include "taiga.h"
#include "theme.h"
#include "win32/win_taskbar.h"

class CDebugTest {
public:
  CDebugTest() : m_dwTick(0) {}
  void Start();
  void End(wstring str, BOOL show);
private:
  DWORD m_dwTick;
};
CDebugTest Test;

// =============================================================================

void DebugTest() {
  // Define variables
  CEpisode episode;
  int value = 0;
  wstring str;

  // Start ticking
  Test.Start();

  for (int i = 0; i < 50000; i++) {
    // Do some tests here
    //       ___
    //      {o,o}
    //      |)__)
    //     --"-"--
    //      O RLY?
  }
  
  // Show result
  Test.End(str, 0);
  
  // Default action
  //ExecuteAction(L"RecognitionTest");

  // oAuth Flow
  /*if (Settings.Announce.Twitter.Enabled && (!Settings.Announce.Twitter.oAuthKey.size() || !Settings.Announce.Twitter.oAuthSecret.size()))*/ {
    OAuthWebRequestSubmit(L"http://twitter.com/oauth/request_token", 
      L"GET", NULL, 
      L"T6XLGzrkfsJAgU59dbIjSA", 
      L"xsvm2NAksjsJGw63RMWAtec3Lz5uiBusfVt48gbdKLg");
    
    //std::map<wstring, wstring> response = ParseQueryString(requestToken);
    //Execute URL
    //wchar_t buf[1024] = {};
    //swprintf_s(buf, SIZEOF(buf), L"http://twitter.com/oauth/authorize?oauth_token=", response[L"oauth_token"].c_str());
    //MessageBox(buf, NULL, 0);
    /*ExecuteLink(wstring(buf));
    //Dialog Here
    CInputDialog oAuthPinGet;
    oAuthPinGet.Title = L"Twitter Authorization";
    oAuthPinGet.Text = L"";
    oAuthPinGet.Info = L"Please Enter the oAuth Pin Shown on the page after logging into Twitter. If you chose to click cancel or leave it blank, Twitter Announcements will be Disabled.";
    oAuthPinGet.Show(this->m_hWindow);*/
    /*if(oAuthPinGet.Result == IDOK && oAuthPinGet.Text.size())
    {
    wstring pin = oAuthPinGet.Text;
    //Trade off Pin and Save Settings
    wstring accessTokenStr = OAuthWebRequestSubmit(L"http://api.twitter.com/oauth/access_token", L"GET", NULL, L"9GZsCbqzjOrsPWlIlysvg", L"ebjXyymbuLtjDvoxle9Ldj8YYIMoleORapIOoqBrjRw", L"", L"", pin);
    std::map<wstring, wstring> access = ParseQueryString(accessTokenStr);
    //Save the Key and Secret
    Settings.Announce.Twitter.oAuthKey = access[L"oauth_token"];
    Settings.Announce.Twitter.oAuthSecret = access[L"oauth_token_secret"];
    }
    else
    {
    Settings.Announce.Twitter.Enabled = false;
    }*/
  }
}

// =============================================================================

void CDebugTest::Start() {
  m_dwTick = GetTickCount();
}

void CDebugTest::End(wstring str, BOOL show) {
  m_dwTick = GetTickCount() - m_dwTick;
  str = ToWSTR(m_dwTick) + L" ms | Text: [" + str + L"]";
  if (show) MainWindow.SetText(str.c_str());
}