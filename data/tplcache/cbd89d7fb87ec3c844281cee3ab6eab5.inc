<li class="Lev1 dropdown {dede:field.currentstyle/}"> <a href="{dede:field name='typeurl'/}" class="menu1 dropdown-toggle" data-toggle="dropdown">{dede:field name='typename'/} 
            {dede:field name=typeid runphp="yes"}
            global $dsql;
            $sql = "SELECT id From `dede_arctype` WHERE reid='@me' And ishidden<>1 order by sortrank asc limit 0, 100 ";
            $row = $dsql->GetOne($sql);      
            @me=is_array($row)?'<i class="fa fa-caret-down"></i>':'';
            {/dede:field}</a>
            <ul {dede:field name=typeid runphp="yes"}
global $dsql;
$sql = "SELECT id From `#@__arctype` WHERE reid='@me' And ishidden<>1 order by sortrank asc limit 0, 100 ";
$row = $dsql->
              GetOne($sql);
              @me=is_array($row)?'class="dropdown-menu sub-menu2" role="menu"':'style="display:none"';
              {/dede:field}>
              
              {dede:channel type='son' noself='yes'}
              <li class="Lev2"> <a href="[field:typeurl/]" class="menu2">[field:typename/]</a> </li>
              {/dede:channel}
            </ul>
          </li>