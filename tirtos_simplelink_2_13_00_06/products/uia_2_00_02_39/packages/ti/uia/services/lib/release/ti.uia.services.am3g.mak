#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = gnu.targets.arm.M3{1,0,4.8,4
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.uia.services/package/package_ti.uia.services.om3g.dep
package/lib/lib/release/ti.uia.services/package/package_ti.uia.services.om3g.dep: ;
endif

package/lib/lib/release/ti.uia.services/package/package_ti.uia.services.om3g: | .interfaces
package/lib/lib/release/ti.uia.services/package/package_ti.uia.services.om3g: package/package_ti.uia.services.c lib/release/ti.uia.services.am3g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm3g $< ...
	$(gnu.targets.arm.M3.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c  -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m3 -mthumb -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2  -I/db/vtree/library/trees/zumaprod/zumaprod-g06/tirtos_simplelink_2_13_00_06/products/bios_6_42_00_08/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.services/package/package_ti.uia.services.om3g: export LD_LIBRARY_PATH=

package/lib/lib/release/ti.uia.services/package/package_ti.uia.services.sm3g: | .interfaces
package/lib/lib/release/ti.uia.services/package/package_ti.uia.services.sm3g: package/package_ti.uia.services.c lib/release/ti.uia.services.am3g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm3g -S $< ...
	$(gnu.targets.arm.M3.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c -S -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m3 -mthumb -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.services/package/package_ti.uia.services.sm3g: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/ti.uia.services/Rta.om3g.dep
package/lib/lib/release/ti.uia.services/Rta.om3g.dep: ;
endif

package/lib/lib/release/ti.uia.services/Rta.om3g: | .interfaces
package/lib/lib/release/ti.uia.services/Rta.om3g: Rta.c lib/release/ti.uia.services.am3g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm3g $< ...
	$(gnu.targets.arm.M3.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c  -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m3 -mthumb -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2  -I/db/vtree/library/trees/zumaprod/zumaprod-g06/tirtos_simplelink_2_13_00_06/products/bios_6_42_00_08/packages/gnu/targets/arm//libs/install-native/arm-none-eabi/include   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.services/Rta.om3g: export LD_LIBRARY_PATH=

package/lib/lib/release/ti.uia.services/Rta.sm3g: | .interfaces
package/lib/lib/release/ti.uia.services/Rta.sm3g: Rta.c lib/release/ti.uia.services.am3g.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clm3g -S $< ...
	$(gnu.targets.arm.M3.rootDir)/bin/arm-none-eabi-gcc -c -MD -MF $@.dep -x c -S -Wunused -Wunknown-pragmas -ffunction-sections -fdata-sections  -mcpu=cortex-m3 -mthumb -mabi=aapcs -g -Dfar= -D__DYNAMIC_REENT__  -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_8_4  -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/ti.uia.services/Rta.sm3g: export LD_LIBRARY_PATH=

clean,m3g ::
	-$(RM) package/lib/lib/release/ti.uia.services/package/package_ti.uia.services.om3g
	-$(RM) package/lib/lib/release/ti.uia.services/Rta.om3g
	-$(RM) package/lib/lib/release/ti.uia.services/package/package_ti.uia.services.sm3g
	-$(RM) package/lib/lib/release/ti.uia.services/Rta.sm3g

lib/release/ti.uia.services.am3g: package/lib/lib/release/ti.uia.services/package/package_ti.uia.services.om3g package/lib/lib/release/ti.uia.services/Rta.om3g lib/release/ti.uia.services.am3g.mak

clean::
	-$(RM) lib/release/ti.uia.services.am3g.mak
