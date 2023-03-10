#include "ResultData.h"

ResultData::ResultData()
{
    link_result_state=false;
    link_param_state=false;
    link_robotset_state=false;
    link_ftp_state=false;
    b_luzhi=false;
#ifdef DEBUG_SSH
    m_bConnectState=false;
    m_bFileState=false;
    ctx_ssh=NULL;
    updata_step=0;
#endif
}

ResultData::~ResultData()
{

}
