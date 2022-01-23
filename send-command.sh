#!/bin/sh

# A shell script to send a command to a TV. The TV will execute the command and immediately return.
# Original: https://github.com/breunigs/bravia-auth-and-remote

cmd="<?xml version=\"1.0\"?><s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\"><s:Body><u:X_SendIRCC xmlns:u=\"urn:schemas-sony-com:service:IRCC:1\"><IRCCCode>$2</IRCCCode></u:X_SendIRCC></s:Body></s:Envelope>"

# X-Auth_PSK: H127CXS is a Pre-Shared Key.
code=$(curl -w "%{http_code}" --silent -XPOST http://$1/sony/IRCC -d "$cmd" -H 'Content-Type: text/xml; charset=UTF-8' -H 'SOAPACTION: "urn:schemas-sony-com:service:IRCC:1#X_SendIRCC"' -H "X-Auth-PSK: H127CXS" -o /dev/null )

if [ "$code" = "200" ]; then
  echo "Success!"
else
  echo "Command failed (HTTP_CODE: $code)"
  exit 1
fi
