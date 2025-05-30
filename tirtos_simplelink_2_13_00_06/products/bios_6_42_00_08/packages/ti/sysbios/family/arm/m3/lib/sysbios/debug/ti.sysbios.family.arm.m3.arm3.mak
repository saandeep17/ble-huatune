#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = iar.targets.arm.M3{1,0,7.40,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/package/package_ti.sysbios.family.arm.m3.orm3.dep
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/package/package_ti.sysbios.family.arm.m3.orm3.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/package/package_ti.sysbios.family.arm.m3.orm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/package/package_ti.sysbios.family.arm.m3.orm3: package/package_ti.sysbios.family.arm.m3.c lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/package/package_ti.sysbios.family.arm.m3.srm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/package/package_ti.sysbios.family.arm.m3.srm3: package/package_ti.sysbios.family.arm.m3.c lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Clobber_asm_iar.orm3.dep
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Clobber_asm_iar.orm3.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Clobber_asm_iar.orm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Clobber_asm_iar.orm3: Clobber_asm_iar.sv7M lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) asmrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iasmarm -S --cpu Cortex-M3 --endian little  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2  -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/IntrinsicsSupport_asm_iar.orm3.dep
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/IntrinsicsSupport_asm_iar.orm3.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/IntrinsicsSupport_asm_iar.orm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/IntrinsicsSupport_asm_iar.orm3: IntrinsicsSupport_asm_iar.sv7M lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) asmrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iasmarm -S --cpu Cortex-M3 --endian little  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2  -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport.orm3.dep
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport.orm3.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport.orm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport.orm3: TaskSupport.c lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport.srm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport.srm3: TaskSupport.c lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport_asm_iar.orm3.dep
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport_asm_iar.orm3.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport_asm_iar.orm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport_asm_iar.orm3: TaskSupport_asm_iar.sv7M lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) asmrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iasmarm -S --cpu Cortex-M3 --endian little  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2  -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi.orm3.dep
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi.orm3.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi.orm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi.orm3: Hwi.c lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi.srm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi.srm3: Hwi.c lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi_asm_iar.orm3.dep
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi_asm_iar.orm3.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi_asm_iar.orm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi_asm_iar.orm3: Hwi_asm_iar.sv7M lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) asmrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iasmarm -S --cpu Cortex-M3 --endian little  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2  -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi_asm_switch_iar.orm3.dep
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi_asm_switch_iar.orm3.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi_asm_switch_iar.orm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi_asm_switch_iar.orm3: Hwi_asm_switch_iar.sv7M lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) asmrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iasmarm -S --cpu Cortex-M3 --endian little  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2  -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Power.orm3.dep
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Power.orm3.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Power.orm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Power.orm3: Power.c lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Power.srm3: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Power.srm3: Power.c lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm3 $< ...
	LC_ALL=C $(iar.targets.arm.M3.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M3 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M3 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_40_2 --debug --dlib_config $(iar.targets.arm.M3.rootDir)/inc/c/DLib_Config_Normal.h  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

clean,rm3 ::
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/package/package_ti.sysbios.family.arm.m3.orm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Clobber_asm_iar.orm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/IntrinsicsSupport_asm_iar.orm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport.orm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport_asm_iar.orm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi.orm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi_asm_iar.orm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi_asm_switch_iar.orm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Power.orm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/package/package_ti.sysbios.family.arm.m3.srm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport.srm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi.srm3
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Power.srm3

lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3: package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/package/package_ti.sysbios.family.arm.m3.orm3 package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Clobber_asm_iar.orm3 package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/IntrinsicsSupport_asm_iar.orm3 package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport.orm3 package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/TaskSupport_asm_iar.orm3 package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi.orm3 package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi_asm_iar.orm3 package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Hwi_asm_switch_iar.orm3 package/lib/lib/sysbios/debug/ti.sysbios.family.arm.m3/Power.orm3 lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak

clean::
	-$(RM) lib/sysbios/debug/ti.sysbios.family.arm.m3.arm3.mak
