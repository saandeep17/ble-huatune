#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = iar.targets.arm.M4{1,0,7.40,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.utils/package/package_ti.sysbios.utils.orm4.dep
package/lib/lib/sysbios/debug/ti.sysbios.utils/package/package_ti.sysbios.utils.orm4.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.utils/package/package_ti.sysbios.utils.orm4: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.utils/package/package_ti.sysbios.utils.orm4: package/package_ti.sysbios.utils.c lib/sysbios/debug/ti.sysbios.utils.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/sysbios/debug/ti.sysbios.utils/package/package_ti.sysbios.utils.srm4: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.utils/package/package_ti.sysbios.utils.srm4: package/package_ti.sysbios.utils.c lib/sysbios/debug/ti.sysbios.utils.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.utils/Load.orm4.dep
package/lib/lib/sysbios/debug/ti.sysbios.utils/Load.orm4.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.utils/Load.orm4: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.utils/Load.orm4: Load.c lib/sysbios/debug/ti.sysbios.utils.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/sysbios/debug/ti.sysbios.utils/Load.srm4: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.utils/Load.srm4: Load.c lib/sysbios/debug/ti.sysbios.utils.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.utils/Load_CPU.orm4.dep
package/lib/lib/sysbios/debug/ti.sysbios.utils/Load_CPU.orm4.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.utils/Load_CPU.orm4: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.utils/Load_CPU.orm4: Load_CPU.c lib/sysbios/debug/ti.sysbios.utils.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/sysbios/debug/ti.sysbios.utils/Load_CPU.srm4: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.utils/Load_CPU.srm4: Load_CPU.c lib/sysbios/debug/ti.sysbios.utils.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

clean,rm4 ::
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.utils/package/package_ti.sysbios.utils.orm4
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.utils/Load.orm4
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.utils/Load_CPU.orm4
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.utils/package/package_ti.sysbios.utils.srm4
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.utils/Load.srm4
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.utils/Load_CPU.srm4

lib/sysbios/debug/ti.sysbios.utils.arm4: package/lib/lib/sysbios/debug/ti.sysbios.utils/package/package_ti.sysbios.utils.orm4 package/lib/lib/sysbios/debug/ti.sysbios.utils/Load.orm4 package/lib/lib/sysbios/debug/ti.sysbios.utils/Load_CPU.orm4 lib/sysbios/debug/ti.sysbios.utils.arm4.mak

clean::
	-$(RM) lib/sysbios/debug/ti.sysbios.utils.arm4.mak
