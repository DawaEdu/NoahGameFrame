// -------------------------------------------------------------------------
//    @FileName			:    NFCTaskModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-06-11
//    @Module           :    NFCTaskModule
//
// -------------------------------------------------------------------------

#ifndef NFC_TASK_MODULE_H
#define NFC_TASK_MODULE_H

#include "NFComm/NFMessageDefine/NFMsgDefine.h"
#include "NFComm/NFPluginModule/NFINetModule.h"
#include "NFComm/NFPluginModule/NFILogModule.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIClassModule.h"
#include "NFComm/NFPluginModule/NFIItemModule.h"
#include "NFComm/NFPluginModule/NFIClassModule.h"
#include "NFComm/NFPluginModule/NFITaskModule.h"
#include "NFComm/NFPluginModule/NFIHeroModule.h"
#include "NFComm/NFPluginModule/NFICommonConfigModule.h"
#include "NFComm/NFPluginModule/NFIGameServerNet_ServerModule.h"

class NFCTaskModule
    : public NFITaskModule
{
public:
    NFCTaskModule( NFIPluginManager* p )
    {
        pPluginManager = p;
    }
    virtual ~NFCTaskModule() {};

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute();
    virtual bool AfterInit();

protected:
		int OnClassObjectEvent( const NFGUID& self, const std::string& strClassNames, const CLASS_OBJECT_EVENT eClassEvent, const NFIDataList& var );

protected:
    void OnClientAcceptTask(const int nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
    void OnClientPushTask(const int nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
    void OnClientPushCustom(const int nSockIndex, const int nMsgID, const char* msg, const uint32_t nLen);
private:
    NFIKernelModule* 				m_pKernelModule;
    NFIPackModule* 					m_pPackModule;
    NFIElementModule* 			m_pElementModule;
    NFIClassModule* 				m_pLogicClassModule;
    NFIPropertyModule* 			m_pPropertyModule;
		NFIHeroModule* 					m_pHeroModule;
		NFICommonConfigModule* 	m_pCommonConfigModule;
		NFIGameServerNet_ServerModule*	m_pGameServerNet_ServerModule;
};


#endif
