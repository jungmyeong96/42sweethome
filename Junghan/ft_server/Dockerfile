FROM	debian:buster

RUN	apt-get update
RUN	apt-get upgrade -y

RUN	apt-get -y install vim curl wget nginx openssl php-fpm php-mysql mariadb-server


COPY	./srcs/default ./etc/nginx/sites-available/default

RUN	openssl req -x509 -nodes -days 365 -newkey rsa:4096 -subj "/C=KR/ST=Seoul/L=Guro/O=42seoul/OU=Gon/CN=junghan" -keyout /etc/ssl/private/localhost.dev.key -out /etc/ssl/certs/localhost.dev.crt


RUN	wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz && \
	tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz && \
	mv phpMyAdmin-5.0.2-all-languages phpmyadmin && \
	mv phpmyadmin /var/www/html/

COPY	./srcs/config.inc.php ./phpmyadmin

RUN	wget https://wordpress.org/latest.tar.gz && \
	tar -xvf latest.tar.gz && \
	mv wordpress/ var/www/html/

COPY	./srcs/wp-config.php /var/www/html/wordpress

RUN	chown -R www-data:www-data /var/www/html/wordpress

EXPOSE 80 443

CMD	service mysql start;\
	service php7.3-fpm start;\
	echo "CREATE USER 'junghan'@'localhost' identified by '';" | mysql -u root --skip-password;\
	echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password;\
	echo "GRANT ALL PRIVILEGES ON *.* TO 'junghan'@'localhost' IDENTIFIED BY '123456' WITH GRANT OPTION" | mysql -u root --skip-password ;\
 	echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password;\
	nginx -g "daemon off;"
