APPNAME = kaguyatc2isis

labels.txt.IGNORELINES = Bytes StartByte ByteOrder TileSamples TileLines

include $(ISISROOT)/make/isismake.tsts

commands:
	$(APPNAME) from=$(INPUT)/TC_EVE_02_N78E003N75E006SC.img \
	  to=$(OUTPUT)/tc_eve_02_006_k2i_spx_noscale.cub setn=y sethrs=y \
	  sethis=y setlrs=y hismi=-20000 hisma=-20000 hrsmi=-21000 \
	  hrsma=-21000 lrsmi=-22000 lrsma=-22000 nullmi=-30000 nullma=-23000 > /dev/null;
	  catlab from=$(OUTPUT)/tc_eve_02_006_k2i_spx_noscale.cub to=$(OUTPUT)/labels.txt > /dev/null;
