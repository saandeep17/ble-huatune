#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = gnu.targets.arm.M4{1,0,4.8,4
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.uia.events/package/package_ti.uia.events.om4g.dep
package/lib/lib/release/ti.uia.events/package/package_ti.uia.events.om4g.dep: ;
endif

package/lib/lib/release/ti.uia.events/package/package_ti.uia.events.om4g: | .interfaces
package/lib/lib/release/ti.uia.events/package/package_ti.uia.events.om4g: package/package_ti.uia.events.c lib/release/ti.uia.events.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c  -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2  -I/db/vtree/library/trees/zumaprod/zumaprod-g06/tirtos_simplelink_2_13_00_06/products/bios_6_42_00_08/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.events/package/package_ti.uia.events.om4g: export LD_LIBRARY_PATH=

package/lib/lib/release/ti.uia.events/package/package_ti.uia.events.sm4g: | .interfaces
package/lib/lib/release/ti.uia.events/package/package_ti.uia.events.sm4g: package/package_ti.uia.events.c lib/release/ti.uia.events.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g -S $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c -S -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.events/package/package_ti.uia.events.sm4g: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.uia.events/UIAAppCtx.om4g.dep
package/lib/lib/release/ti.uia.events/UIAAppCtx.om4g.dep: ;
endif

package/lib/lib/release/ti.uia.events/UIAAppCtx.om4g: | .interfaces
package/lib/lib/release/ti.uia.events/UIAAppCtx.om4g: UIAAppCtx.c lib/release/ti.uia.events.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c  -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2  -I/db/vtree/library/trees/zumaprod/zumaprod-g06/tirtos_simplelink_2_13_00_06/products/bios_6_42_00_08/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.events/UIAAppCtx.om4g: export LD_LIBRARY_PATH=

package/lib/lib/release/ti.uia.events/UIAAppCtx.sm4g: | .interfaces
package/lib/lib/release/ti.uia.events/UIAAppCtx.sm4g: UIAAppCtx.c lib/release/ti.uia.events.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g -S $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c -S -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.events/UIAAppCtx.sm4g: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.uia.events/UIAChanCtx.om4g.dep
package/lib/lib/release/ti.uia.events/UIAChanCtx.om4g.dep: ;
endif

package/lib/lib/release/ti.uia.events/UIAChanCtx.om4g: | .interfaces
package/lib/lib/release/ti.uia.events/UIAChanCtx.om4g: UIAChanCtx.c lib/release/ti.uia.events.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c  -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2  -I/db/vtree/library/trees/zumaprod/zumaprod-g06/tirtos_simplelink_2_13_00_06/products/bios_6_42_00_08/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.events/UIAChanCtx.om4g: export LD_LIBRARY_PATH=

package/lib/lib/release/ti.uia.events/UIAChanCtx.sm4g: | .interfaces
package/lib/lib/release/ti.uia.events/UIAChanCtx.sm4g: UIAChanCtx.c lib/release/ti.uia.events.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g -S $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c -S -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.events/UIAChanCtx.sm4g: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.uia.events/UIAFrameCtx.om4g.dep
package/lib/lib/release/ti.uia.events/UIAFrameCtx.om4g.dep: ;
endif

package/lib/lib/release/ti.uia.events/UIAFrameCtx.om4g: | .interfaces
package/lib/lib/release/ti.uia.events/UIAFrameCtx.om4g: UIAFrameCtx.c lib/release/ti.uia.events.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c  -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2  -I/db/vtree/library/trees/zumaprod/zumaprod-g06/tirtos_simplelink_2_13_00_06/products/bios_6_42_00_08/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.events/UIAFrameCtx.om4g: export LD_LIBRARY_PATH=

package/lib/lib/release/ti.uia.events/UIAFrameCtx.sm4g: | .interfaces
package/lib/lib/release/ti.uia.events/UIAFrameCtx.sm4g: UIAFrameCtx.c lib/release/ti.uia.events.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g -S $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c -S -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.events/UIAFrameCtx.sm4g: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.uia.events/UIAThreadCtx.om4g.dep
package/lib/lib/release/ti.uia.events/UIAThreadCtx.om4g.dep: ;
endif

package/lib/lib/release/ti.uia.events/UIAThreadCtx.om4g: | .interfaces
package/lib/lib/release/ti.uia.events/UIAThreadCtx.om4g: UIAThreadCtx.c lib/release/ti.uia.events.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c  -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2  -I/db/vtree/library/trees/zumaprod/zumaprod-g06/tirtos_simplelink_2_13_00_06/products/bios_6_42_00_08/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.events/UIAThreadCtx.om4g: export LD_LIBRARY_PATH=

package/lib/lib/release/ti.uia.events/UIAThreadCtx.sm4g: | .interfaces
package/lib/lib/release/ti.uia.events/UIAThreadCtx.sm4g: UIAThreadCtx.c lib/release/ti.uia.events.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g -S $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c -S -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.events/UIAThreadCtx.sm4g: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.uia.events/UIAUserCtx.om4g.dep
package/lib/lib/release/ti.uia.events/UIAUserCtx.om4g.dep: ;
endif

package/lib/lib/release/ti.uia.events/UIAUserCtx.om4g: | .interfaces
package/lib/lib/release/ti.uia.events/UIAUserCtx.om4g: UIAUserCtx.c lib/release/ti.uia.events.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c  -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2  -I/db/vtree/library/trees/zumaprod/zumaprod-g06/tirtos_simplelink_2_13_00_06/products/bios_6_42_00_08/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.events/UIAUserCtx.om4g: export LD_LIBRARY_PATH=

package/lib/lib/release/ti.uia.events/UIAUserCtx.sm4g: | .interfaces
package/lib/lib/release/ti.uia.events/UIAUserCtx.sm4g: UIAUserCtx.c lib/release/ti.uia.events.am4g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm4g -S $< ...
	$(gnu.targets.arm.M4.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c -S -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M4 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.events/UIAUserCtx.sm4g: export LD_LIBRARY_PATH=

clean,m4g ::
	-$(RM) package/lib/lib/release/ti.uia.events/package/package_ti.uia.events.om4g
	-$(RM) package/lib/lib/release/ti.uia.events/UIAAppCtx.om4g
	-$(RM) package/lib/lib/release/ti.uia.events/UIAChanCtx.om4g
	-$(RM) package/lib/lib/release/ti.uia.events/UIAFrameCtx.om4g
	-$(RM) package/lib/lib/release/ti.uia.events/UIAThreadCtx.om4g
	-$(RM) package/lib/lib/release/ti.uia.events/UIAUserCtx.om4g
	-$(RM) package/lib/lib/release/ti.uia.events/package/package_ti.uia.events.sm4g
	-$(RM) package/lib/lib/release/ti.uia.events/UIAAppCtx.sm4g
	-$(RM) package/lib/lib/release/ti.uia.events/UIAChanCtx.sm4g
	-$(RM) package/lib/lib/release/ti.uia.events/UIAFrameCtx.sm4g
	-$(RM) package/lib/lib/release/ti.uia.events/UIAThreadCtx.sm4g
	-$(RM) package/lib/lib/release/ti.uia.events/UIAUserCtx.sm4g

lib/release/ti.uia.events.am4g: package/lib/lib/release/ti.uia.events/package/package_ti.uia.events.om4g package/lib/lib/release/ti.uia.events/UIAAppCtx.om4g package/lib/lib/release/ti.uia.events/UIAChanCtx.om4g package/lib/lib/release/ti.uia.events/UIAFrameCtx.om4g package/lib/lib/release/ti.uia.events/UIAThreadCtx.om4g package/lib/lib/release/ti.uia.events/UIAUserCtx.om4g lib/release/ti.uia.events.am4g.mak

clean::
	-$(RM) lib/release/ti.uia.events.am4g.mak
