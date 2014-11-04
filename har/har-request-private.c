
static void _value_transform_soup_message_har_request (const GValue *src_value, GValue *dest_value)
{
  SoupMessage * soup_msg;
  HarRequest * har_req;

  g_return_if_fail (src_value != NULL);
  g_return_if_fail (dest_value != NULL);
  g_return_if_fail (G_IS_VALUE (src_value));
  g_return_if_fail (G_IS_VALUE (dest_value));
  g_return_if_fail (G_VALUE_HOLDS (src_value, SOUP_TYPE_MESSAGE));
  g_return_if_fail (G_VALUE_HOLDS (dest_value, HAR_TYPE_REQUEST));

  soup_msg = SOUP_MESSAGE (g_value_peek_pointer (src_value));
  har_req = HAR_REQUEST (g_value_peek_pointer (dest_value));

  har_request_transform_from_soup_message(har_req, soup_msg);
}

static void _value_transform_har_request_soup_message (const GValue *src_value, GValue *dest_value)
{
  HarRequest * har_req;
  SoupMessage * soup_msg;

  g_return_if_fail (src_value != NULL);
  g_return_if_fail (dest_value != NULL);
  g_return_if_fail (G_IS_VALUE (src_value));
  g_return_if_fail (G_IS_VALUE (dest_value));
  g_return_if_fail (G_VALUE_HOLDS (src_value, HAR_TYPE_REQUEST));
  g_return_if_fail (G_VALUE_HOLDS (dest_value, CURL_TYPE_EASY));

  har_req = HAR_REQUEST (g_value_peek_pointer (src_value));
  soup_msg = SOUP_MESSAGE (g_value_peek_pointer (dest_value));

  har_request_transform_to_soup_message(har_req, soup_msg);
}

static void _value_transform_curl_easy_har_request (const GValue *src_value, GValue *dest_value)
{
  CurlEasy * curl_easy;
  HarRequest * har_req;

  g_return_if_fail (src_value != NULL);
  g_return_if_fail (dest_value != NULL);
  g_return_if_fail (G_IS_VALUE (src_value));
  g_return_if_fail (G_IS_VALUE (dest_value));
  g_return_if_fail (G_VALUE_HOLDS (src_value, CURL_TYPE_EASY));
  g_return_if_fail (G_VALUE_HOLDS (dest_value, HAR_TYPE_REQUEST));

  curl_easy = CURL_EASY (g_value_peek_pointer (src_value));
  har_req = HAR_REQUEST (g_value_peek_pointer (dest_value));

  har_request_transform_from_curl_easy(har_req, curl_easy->handle);
}

static void _value_transform_har_request_curl_easy (const GValue *src_value, GValue *dest_value)
{
  HarRequest * har_req;
  CurlEasy * curl_easy;

  g_return_if_fail (src_value != NULL);
  g_return_if_fail (dest_value != NULL);
  g_return_if_fail (G_IS_VALUE (src_value));
  g_return_if_fail (G_IS_VALUE (dest_value));
  g_return_if_fail (G_VALUE_HOLDS (src_value, HAR_TYPE_REQUEST));
  g_return_if_fail (G_VALUE_HOLDS (dest_value, CURL_TYPE_EASY));

  har_req = HAR_REQUEST (g_value_peek_pointer (src_value));
  curl_easy = CURL_EASY (g_value_peek_pointer (dest_value));

  har_request_transform_to_curl_easy(har_req, curl_easy->handle);
}
