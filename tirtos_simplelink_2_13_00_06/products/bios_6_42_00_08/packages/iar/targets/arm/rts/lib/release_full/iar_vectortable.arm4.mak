#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = iar.targets.arm.M4{1,0,7.40,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release_full/iar_vectortable/package/package_iar.targets.arm.rts.orm4.dep
package/lib/lib/release_full/iar_vectortable/package/package_iar.targets.arm.rts.orm4.dep: ;
endif

package/lib/lib/release_full/iar_vectortable/package/package_iar.targets.arm.rts.orm4: | .interfaces
package/lib/lib/release_full/iar_vectortable/package/package_iar.targets.arm.rts.orm4: package/package_iar.targets.arm.rts.c lib/release_full/iar_vectortable.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release_full -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Full.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/release_full/iar_vectortable/package/package_iar.targets.arm.rts.srm4: | .interfaces
package/lib/lib/release_full/iar_vectortable/package/package_iar.targets.arm.rts.srm4: package/package_iar.targets.arm.rts.c lib/release_full/iar_vectortable.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release_full -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Full.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release_full/iar_vectortable/VectorTable.orm4.dep
package/lib/lib/release_full/iar_vectortable/VectorTable.orm4.dep: ;
endif

package/lib/lib/release_full/iar_vectortable/VectorTable.orm4: | .interfaces
package/lib/lib/release_full/iar_vectortable/VectorTable.orm4: VectorTable.c lib/release_full/iar_vectortable.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release_full -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Full.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

package/lib/lib/release_full/iar_vectortable/VectorTable.srm4: | .interfaces
package/lib/lib/release_full/iar_vectortable/VectorTable.srm4: VectorTable.c lib/release_full/iar_vectortable.arm4.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clrm4 $< ...
	LC_ALL=C $(iar.targets.arm.M4.rootDir)/bin/iccarm  --silent --aeabi --cpu=Cortex-M4 --diag_suppress=Pa050,Go005 --endian=little -e --thumb  -Dxdc_target_name__=M4 -Dxdc_target_types__=iar/targets/arm/std.h -Dxdc_bld__profile_release_full -Dxdc_bld__vers_1_0_7_40_2 -Ohs --dlib_config $(iar.targets.arm.M4.rootDir)/inc/c/DLib_Config_Full.h  $(XDCINCS)  -o $@  $<
	
	-@$(FIXDEP) $@.dep $@.dep
	

clean,rm4 ::
	-$(RM) package/lib/lib/release_full/iar_vectortable/package/package_iar.targets.arm.rts.orm4
	-$(RM) package/lib/lib/release_full/iar_vectortable/VectorTable.orm4
	-$(RM) package/lib/lib/release_full/iar_vectortable/package/package_iar.targets.arm.rts.srm4
	-$(RM) package/lib/lib/release_full/iar_vectortable/VectorTable.srm4

lib/release_full/iar_vectortable.arm4: package/lib/lib/release_full/iar_vectortable/package/package_iar.targets.arm.rts.orm4 package/lib/lib/release_full/iar_vectortable/VectorTable.orm4 lib/release_full/iar_vectortable.arm4.mak

clean::
	-$(RM) lib/release_full/iar_vectortable.arm4.mak
