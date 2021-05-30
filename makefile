DIR :=  src 


all :
	for i in $(DIR) ; do \
		(cd $$i && echo "making $$i" && $(MAKE)) || exit 1 ; \
	done

clean :
	for i in $(DIR) ; do \
		(cd $$i && echo "cleaning $$i" && $(MAKE) clean ) || exit 1 ; \
	done






