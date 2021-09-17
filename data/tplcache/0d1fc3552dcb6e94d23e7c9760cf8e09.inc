<div class="col-md-3 col-sm-6 hidden-sm hidden-xs foot-nav">
          <h2 class="ft-title"><span><a href="{dede:field name='typeurl'/}">{dede:field name='typename'/}</a></span></h2>
          <div id="twitter-feed" class="twitter-feed">
            <ul class="foot-nav-menu">
              {dede:channel type='son' noself='yes'}
              <li><a href="[field:typeurl/]"><i class="fa fa-caret-right"></i> &nbsp;[field:typename/]</a></li>
              {/dede:channel}
            </ul>
          </div>
        </div>