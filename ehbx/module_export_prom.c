#include<curl/curl.h>

static size_t	write_callback(void *ptr, size_t size, size_t nmemb, void *userdata)
{
	size_t	r_size = size * nmemb;

	zbx_httppage_t	*page = (zbx_httppage_t	*)userdata;

	zbx_strncpy_alloc(&page->data, &page->alloc, &page->offset, ptr, r_size);

	return r_size;
}

void export_to_pushgateway(char *buffer)
{
  CURL *ehbx_handle = curl_easy_init();
  if ( CURLE_OK == curl_easy_setopt(ehbx_handle, CURLOPT_URL, "http://localhost:9091/metrics/job/zabbix/instance/float") &&
      CURLE_OK == curl_easy_setopt(ehbx_handle, CURLOPT_POST, 1L) &&
      CURLE_OK == curl_easy_setopt(ehbx_handle, CURLOPT_POSTFIELDS, buffer) &&
      CURL_OK == curl_easy_setopt(ehbx_handle, CURLOPT_WRITEFUNCTION, write_callback)
      )
  {
    curl_easy_send(buffer);
  }
}

static void	dummy_history_float_cb(const ZBX_HISTORY_FLOAT *history, int history_num)
{
	int	i;
	DC_ITEM			*items;
	int			*errcodes;
	zbx_uint64_t *itemids;

	if (0 != history_num)
	{
		items = (DC_ITEM *)zbx_malloc(NULL, sizeof(DC_ITEM) * (size_t)history_num);
		errcodes = (int *)zbx_malloc(NULL, sizeof(int) * (size_t)history_num);
		itemids = (zbx_uint64_t *)zbx_malloc(NULL, sizeof(zbx_uint64_t) * (size_t)history_num);
		
		for (i=0; i< history_num; i++)
			itemids[i] = history[i].itemid;
		
		LOCK_CACHE;	
		DCconfig_get_items_by_itemids(items, itemids, errcodes, (size_t)history_num);
		UNLOCK_CACHE;

		for (i = 0; i < history_num; i++)
		{
			zabbix_log(LOG_LEVEL_WARNING, "exporting history: itemid[%d],key[%s],value[%f]", itemids[i],items[i].key_orig,history[i].value);		
		}	

		zbx_free(errcodes);
		zbx_free(items);
		zbx_free(itemids);
	}
}

  
    
