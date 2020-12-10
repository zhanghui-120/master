// plc_manager.h文件头注释
/**
* @file plc_manager.h
* @author hui zhang (hui_zhang@roboticplus.com)
* @brief 任务执行类
* @version 1.0.0
* @date 2020-12-1
*
* @copyright Copyright (c) roboticplus 2020
**/

#ifndef PLCMANAGER_LINE_PLC_MANAGER_LINE_PLC_MANAGER_H
#define PLCMANAGER_LINE_PLC_MANAGER_LINE_PLC_MANAGER_H

#include "plc_manager/receive_tcp_data.h"
#include "plc_manager/receive_data.h"
#include <thread>
#include <fstream>
#include <jsoncpp/json/json.h>
#include <stdlib.h>

namespace plc_manager
{

/**
 * @class:plc数据反馈解析和控制
 * 
 */
class PlcManager
{
public:
  PlcManager();
  ~PlcManager();

  /**
   * @brief:增加PublishThread线程与SubscribeThread线程
   *
   */
  void startUp();

  /**
   * @brief:接收tcp数据并发布线程 
   *
   */
  void addPublishThread();

  /**
   * @brief:订阅线程
   *
   */
  void addSubscribeThread();

  /**
   * @brief:发布控制指令
   *
   */
  void addClientThread();

  /**
   * @brief:控制机械臂线程 
   *
   */  
  void addServiceThread();

  /**
   * @brief:解析机械臂传来的数据
   *
   */
  bool decodeBuffer(const char *buffer, int len);
  
  /**
   * @brief:改变循环条件的状态
   * 
   */
  void changeState();

  bool writeJson();
  
  /**
   * @brief:订阅机械臂位置数据信息
   * 
   */
  void addJointState();

private:
  int recv_length_;
  bool keep_running_;
  int socket_;
  SubscribeAndPublish test_message_sub_;
  struct plcData data_;
};

}//namespace 

#endif // end PLCMANAGER_LINE_PLC_MANAGER_LINE_PLC_MANAGER_H