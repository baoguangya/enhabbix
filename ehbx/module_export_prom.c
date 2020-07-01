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
  
    
