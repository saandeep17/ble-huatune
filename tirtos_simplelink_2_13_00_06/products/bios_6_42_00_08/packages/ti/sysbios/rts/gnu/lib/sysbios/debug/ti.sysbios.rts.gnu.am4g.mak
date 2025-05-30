#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = gnu.targets.arm.M4{1,0,4.8,4
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/package/package_ti.sysbios.rts.gnu.om4g.dep
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/package/package_ti.sysbios.rts.gnu.om4g.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/package/package_ti.sysbios.rts.gnu.om4g: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/package/package_ti.sysbios.rts.gnu.om4g: package/package_ti.sysbios.rts.gnu.c lib/sysbios/debug/ti.sysbios.rts.gnu.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c  -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -D_DEBUG_=1 -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_8_4 -g  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE -I/db/vtree/library/trees/zumaprod/zumaprod-g06/tirtos_simplelink_2_13_00_06/products/bios_6_42_00_08/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/package/package_ti.sysbios.rts.gnu.om4g: export LD_LIBRARY_PATH=

package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/package/package_ti.sysbios.rts.gnu.sm4g: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/package/package_ti.sysbios.rts.gnu.sm4g: package/package_ti.sysbios.rts.gnu.c lib/sysbios/debug/ti.sysbios.rts.gnu.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g -S $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c -S -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -D_DEBUG_=1 -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_8_4 -g  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/package/package_ti.sysbios.rts.gnu.sm4g: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/ReentSupport.om4g.dep
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/ReentSupport.om4g.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/ReentSupport.om4g: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/ReentSupport.om4g: ReentSupport.c lib/sysbios/debug/ti.sysbios.rts.gnu.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c  -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -D_DEBUG_=1 -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_8_4 -g  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE -I/db/vtree/library/trees/zumaprod/zumaprod-g06/tirtos_simplelink_2_13_00_06/products/bios_6_42_00_08/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/ReentSupport.om4g: export LD_LIBRARY_PATH=

package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/ReentSupport.sm4g: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/ReentSupport.sm4g: ReentSupport.c lib/sysbios/debug/ti.sysbios.rts.gnu.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g -S $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c -S -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -D_DEBUG_=1 -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_8_4 -g  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/ReentSupport.sm4g: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/SemiHostSupport.om4g.dep
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/SemiHostSupport.om4g.dep: ;
endif

package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/SemiHostSupport.om4g: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/SemiHostSupport.om4g: SemiHostSupport.c lib/sysbios/debug/ti.sysbios.rts.gnu.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c  -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -D_DEBUG_=1 -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_8_4 -g  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE -I/db/vtree/library/trees/zumaprod/zumaprod-g06/tirtos_simplelink_2_13_00_06/products/bios_6_42_00_08/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/SemiHostSupport.om4g: export LD_LIBRARY_PATH=

package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/SemiHostSupport.sm4g: | .interfaces
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/SemiHostSupport.sm4g: SemiHostSupport.c lib/sysbios/debug/ti.sysbios.rts.gnu.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g -S $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c -S -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -D_DEBUG_=1 -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_8_4 -g  -Dti_sysbios_Build_useHwiMacros -Dti_sysbios_BIOS_smpEnabled__D=FALSE  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/SemiHostSupport.sm4g: export LD_LIBRARY_PATH=

clean,m4g ::
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/package/package_ti.sysbios.rts.gnu.om4g
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/ReentSupport.om4g
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/SemiHostSupport.om4g
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/package/package_ti.sysbios.rts.gnu.sm4g
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/ReentSupport.sm4g
	-$(RM) package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/SemiHostSupport.sm4g

lib/sysbios/debug/ti.sysbios.rts.gnu.am4g: package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/package/package_ti.sysbios.rts.gnu.om4g package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/ReentSupport.om4g package/lib/lib/sysbios/debug/ti.sysbios.rts.gnu/SemiHostSupport.om4g lib/sysbios/debug/ti.sysbios.rts.gnu.am4g.mak

clean::
	-$(RM) lib/sysbios/debug/ti.sysbios.rts.gnu.am4g.mak
