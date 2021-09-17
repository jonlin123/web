<?php
/**
 * 用户管理
 *
 * @version        $Id: sys_admin_user.php 1 16:22 2010年7月20日Z tianya $
 * @package        DedeCMS.Administrator
 * @copyright      Copyright (c) 2007 - 2010, DesDev, Inc.
 * @license        http://help.dedecms.com/usersguide/license.html
 * @link           http://www.dedecms.com
 */
require_once(dirname(__FILE__)."/config.php");
CheckPurview('sys_User');
require_once(DEDEINC."/datalistcp.class.php");

$query = "SELECT * FROM dede_user";
$dlist = new DataListCP();
$dlist->SetTemplet(DEDEADMIN."/templets/sys_user.htm");
$dlist->SetSource($query);
$dlist->Display();

function GetUserType($trank)
{
    global $adminRanks;
    if(isset($adminRanks[$trank])) return $adminRanks[$trank];
    else return "错误类型";
}

function GetChannel($c)
{
    if($c==""||$c==0) return "所有频道";
    else return $c;
}