#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = iar.targets.arm.M3{1,0,7.40,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.syncs/package/package_ti.sysbios.syncs.orm3.dep
package/lib/lib/sysbios/debug/ti.sysbios.syncs/package/package_ti.sysbios.syncs.orm3.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.syncs/package/package_ti.sysbios.syncs.orm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.syncs/package/package_ti.sysbios.syncs.orm3: package/package_ti.sysbios.syncs.c lib/sysbios/debug/ti.sysbios.syncs.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/sysbios/debug/ti.sysbios.syncs/package/package_ti.sysbios.syncs.srm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.syncs/package/package_ti.sysbios.syncs.srm3: package/package_ti.sysbios.syncs.c lib/sysbios/debug/ti.sysbios.syncs.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSem.orm3.dep
package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSem.orm3.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSem.orm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSem.orm3: SyncSem.c lib/sysbios/debug/ti.sysbios.syncs.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSem.srm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSem.srm3: SyncSem.c lib/sysbios/debug/ti.sysbios.syncs.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSwi.orm3.dep
package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSwi.orm3.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSwi.orm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSwi.orm3: SyncSwi.c lib/sysbios/debug/ti.sysbios.syncs.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSwi.srm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSwi.srm3: SyncSwi.c lib/sysbios/debug/ti.sysbios.syncs.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncEvent.orm3.dep
package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncEvent.orm3.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncEvent.orm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncEvent.orm3: SyncEvent.c lib/sysbios/debug/ti.sysbios.syncs.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncEvent.srm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncEvent.srm3: SyncEvent.c lib/sysbios/debug/ti.sysbios.syncs.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

clean,rm3 ::
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.syncs/package/package_ti.sysbios.syncs.orm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSem.orm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSwi.orm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncEvent.orm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.syncs/package/package_ti.sysbios.syncs.srm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSem.srm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSwi.srm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncEvent.srm3

lib/sysbios/debug/ti.sysbios.syncs.arm3: package/lib/lib/sysbios/debug/ti.sysbios.syncs/package/package_ti.sysbios.syncs.orm3 package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSem.orm3 package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncSwi.orm3 package/lib/lib/sysbios/debug/ti.sysbios.syncs/SyncEvent.orm3 lib/sysbios/debug/ti.sysbios.syncs.arm3.mak

clean::
	-$(RM) lib/sysbios/debug/ti.sysbios.syncs.arm3.mak
