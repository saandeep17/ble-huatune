#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = iar.targets.arm.M3{1,0,7.40,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.uia.sysbios/package/package_ti.uia.sysbios.orm3.dep
package/lib/lib/release/ti.uia.sysbios/package/package_ti.uia.sysbios.orm3.dep: ;
endif

package/lib/lib/release/ti.uia.sysbios/package/package_ti.uia.sysbios.orm3: | .interfaces
package/lib/lib/release/ti.uia.sysbios/package/package_ti.uia.sysbios.orm3: package/package_ti.uia.sysbios.c lib/release/ti.uia.sysbios.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/release/ti.uia.sysbios/package/package_ti.uia.sysbios.srm3: | .interfaces
package/lib/lib/release/ti.uia.sysbios/package/package_ti.uia.sysbios.srm3: package/package_ti.uia.sysbios.c lib/release/ti.uia.sysbios.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.uia.sysbios/LoggerStreamer.orm3.dep
package/lib/lib/release/ti.uia.sysbios/LoggerStreamer.orm3.dep: ;
endif

package/lib/lib/release/ti.uia.sysbios/LoggerStreamer.orm3: | .interfaces
package/lib/lib/release/ti.uia.sysbios/LoggerStreamer.orm3: LoggerStreamer.c lib/release/ti.uia.sysbios.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/release/ti.uia.sysbios/LoggerStreamer.srm3: | .interfaces
package/lib/lib/release/ti.uia.sysbios/LoggerStreamer.srm3: LoggerStreamer.c lib/release/ti.uia.sysbios.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.uia.sysbios/LoggerStreamer2.orm3.dep
package/lib/lib/release/ti.uia.sysbios/LoggerStreamer2.orm3.dep: ;
endif

package/lib/lib/release/ti.uia.sysbios/LoggerStreamer2.orm3: | .interfaces
package/lib/lib/release/ti.uia.sysbios/LoggerStreamer2.orm3: LoggerStreamer2.c lib/release/ti.uia.sysbios.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/release/ti.uia.sysbios/LoggerStreamer2.srm3: | .interfaces
package/lib/lib/release/ti.uia.sysbios/LoggerStreamer2.srm3: LoggerStreamer2.c lib/release/ti.uia.sysbios.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.uia.sysbios/LoggerIdle.orm3.dep
package/lib/lib/release/ti.uia.sysbios/LoggerIdle.orm3.dep: ;
endif

package/lib/lib/release/ti.uia.sysbios/LoggerIdle.orm3: | .interfaces
package/lib/lib/release/ti.uia.sysbios/LoggerIdle.orm3: LoggerIdle.c lib/release/ti.uia.sysbios.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/release/ti.uia.sysbios/LoggerIdle.srm3: | .interfaces
package/lib/lib/release/ti.uia.sysbios/LoggerIdle.srm3: LoggerIdle.c lib/release/ti.uia.sysbios.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

clean,rm3 ::
	-$(RM) package/lib/lib/release/ti.uia.sysbios/package/package_ti.uia.sysbios.orm3
	-$(RM) package/lib/lib/release/ti.uia.sysbios/LoggerStreamer.orm3
	-$(RM) package/lib/lib/release/ti.uia.sysbios/LoggerStreamer2.orm3
	-$(RM) package/lib/lib/release/ti.uia.sysbios/LoggerIdle.orm3
	-$(RM) package/lib/lib/release/ti.uia.sysbios/package/package_ti.uia.sysbios.srm3
	-$(RM) package/lib/lib/release/ti.uia.sysbios/LoggerStreamer.srm3
	-$(RM) package/lib/lib/release/ti.uia.sysbios/LoggerStreamer2.srm3
	-$(RM) package/lib/lib/release/ti.uia.sysbios/LoggerIdle.srm3

lib/release/ti.uia.sysbios.arm3: package/lib/lib/release/ti.uia.sysbios/package/package_ti.uia.sysbios.orm3 package/lib/lib/release/ti.uia.sysbios/LoggerStreamer.orm3 package/lib/lib/release/ti.uia.sysbios/LoggerStreamer2.orm3 package/lib/lib/release/ti.uia.sysbios/LoggerIdle.orm3 lib/release/ti.uia.sysbios.arm3.mak

clean::
	-$(RM) lib/release/ti.uia.sysbios.arm3.mak
