#define _GNU_SOURCE 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define MAX_LEN 1024

int main() {
	char buffer[MAX_LEN], new_title[MAX_LEN];
	char *title, *c_type, *c_theme, *c_format;
	const char *html_c, *nav_c, *div_c, *padding, *nav_f, *nav_li, *div_f;
	int type = 0, theme = 0, format = 0;	
	struct stat st = {0};
	FILE *css, *blog, *archive, *about, *port, *proj, *course, *syll, *sched, *res;	

	printf("------------------------------------------------------\n");
	printf("Welcome to boil, a command line static site generator!\n");

	printf("Enter a title: ");
	if (fgets(buffer, MAX_LEN, stdin))
  	asprintf(&title, "%s", buffer);

	memset(new_title, 0, MAX_LEN);
	strncpy(new_title, title, strlen(title) - 1);	

	if (stat("site", &st) == -1) {
    mkdir("site", 0700);
	} else {
		remove("site/theme");

		if (access("site/blog.html", F_OK) != -1) {
			remove("site/blog.html");
			remove("site/archive.html");
			remove("site/about.html");
		} else if (access("site/port.html", F_OK) != -1) {
			remove("site/port.html");
			remove("site/proj.html");
		} else {
			remove("site/course.html");
			remove("site/syll.html");
			remove("site/sched.html");
			remove("site/res.html");
		}

		rmdir("site");				
	}

	while (type != 1 && type != 2 && type != 3) {
		printf("Enter the number of your site type (Blog - 1) (Portfolio - 2) (Course - 3): ");
		if (fgets(buffer, MAX_LEN, stdin))
  		asprintf(&c_type, "%s", buffer);
  	type = atoi(c_type);
	}

	while (theme != 1 && theme != 2 && theme != 3 && theme != 4 && theme != 5) {
		printf("Enter the number of your color theme (Default - 1) (Sky - 2) (Lava - 3) (Pumpkin - 4) (Forest - 5): ");
		if (fgets(buffer, MAX_LEN, stdin))
  		asprintf(&c_theme, "%s", buffer);
  	theme = atoi(c_theme);
	}

	/*
	 * Default has the menu horizontally near the top.
	 * Sidemenu has the menu on the left side. No menu 
	 * has the menu elements distributed on the page, 
	 */
	while (format != 1 && format != 2) {
		printf("Enter the number of your formatting (Default - 1) (Sidemenu - 2): ");
		if (fgets(buffer, MAX_LEN, stdin))
  		asprintf(&c_format, "%s", buffer);
  	format = atoi(c_format);
	}

	if (type == 1) {
		blog = fopen("site/blog.html", "w");
		fprintf(blog, "<!-- Blog. -->\n<!DOCTYPE html>\n<html>\n<head>\n  <title>%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" href=\"theme.css\">\n  <link href=\"https://fonts.googleapis.com/css?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<body>\n  <h1>%s</h1>\n", new_title, new_title);
		fprintf(blog, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"blog.html\">Home</a></li>\n   <li id=\"nav-li\"><a href =\"archive.html\">Archive</a></li>\n   <li id=\"nav-li\"><a href =\"about.html\">About</a></li>\n  </ul>\n  <div>\n  \t<h3>January 1</h3>\n  \t<p>My first post.</p>\n  </div>\n</body>\n</html>\n");
		fclose(blog);		

		archive = fopen("site/archive.html", "w");
		fprintf(archive, "<!-- Archive. -->\n<!DOCTYPE html>\n<html>\n<head>\n  <title>%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" href=\"theme.css\">\n  <link href=\"https://fonts.googleapis.com/css?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<body>\n\t<h1>%s</h1>\n", new_title, new_title);
		fprintf(archive, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href =\"blog.html\">Home</a></li>\n   <li id=\"nav-li\"><a href =\"archive.html\">Archive</a></li>\n   <li id=\"nav-li\"><a href =\"about.html\">About</a></li>\n  </ul>\n  <div>\n  \t<ul>\n      <l1>Previous Post 1</l1>\n      <li>Previous Post 2</li>\n    </ul>\n  <div>\n</body>\n</html>\n");
		fclose(archive);

		about = fopen("site/about.html", "w");
		fprintf(about, "<!-- About. -->\n<!DOCTYPE html>\n<html>\n<head>\n  <title>%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" href=\"theme.css\">\n  <link href=\"https://fonts.googleapis.com/css?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<body>\n\t<h1>%s</h1>\n", new_title, new_title);
		fprintf(about, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"blog.html\">Home</a></li>\n   <li id=\"nav-li\"><a href=\"archive.html\">Archive</a></li>\n   <li id=\"nav-li\"><a href=\"about.html\">About</a></li>\n  </ul>\n  <div>\n  \t<p>My description.</p>\n  <div>\n</body>\n</html>");
		fclose(about);		
	} else if (type == 2) {
		port = fopen("site/port.html", "w");
		fprintf(port, "<!-- Portfolio. -->\n<!DOCTYPE html>\n<head>\n  <title>%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" href=\"theme.css\">\n  <link href=\"https://fonts.googleapis.com/css?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<body>\n\t<h1>%s</h1>\n  ", new_title, new_title);
		fprintf(port, "<ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"port.html\">Home</a></li>\n   <li id=\"nav-li\"><a href=\"proj.html\">Projects</a></li>\n   <li id=\"nav-li\">Resume</li> <!-- Link to PDF. -->\n   <li id=\"nav-li\">CV</li> <!-- Link to PDF. -->\n  </ul>\n  <div>\n    <h3>About Me</h3>\n    <p>My description.</p>\n  </div>\n</body>\n</html>");
		fclose(port); 	

		proj = fopen("site/proj.html", "w");
		fprintf(proj, "<!-- Portfolio. -->\n<!DOCTYPE html>\n<head>\n  <title>%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" href=\"theme.css\">\n  <link href=\"https://fonts.googleapis.com/css?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<body>\n\t<h1>%s</h1>\n  ", new_title, new_title);
		fprintf(proj, "<ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"port.html\">Home</a></li>\n   <li id=\"nav-li\"><a href=\"proj.html\">Projects</a></li>\n   <li id=\"nav-li\">Resume</li> <!-- Link to PDF. -->\n   <li id=\"nav-li\">CV</li> <!-- Link to PDF. -->\n  </ul>\n  <div>\n    <h3>Project 1</h3>\n    <p>My description.</p>\n    <h3>Project 2</h3>\n    <p>My description.</p>\n  </div>\n</body>\n</html>");
	} else if (type == 3) {
		course = fopen("site/course.html", "w");
		fprintf(course, "<!-- Course -->\n<!DOCTYPE html>\n<html>\n<head>\n  <title>%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" href=\"theme.css\">\n  <link href=\"https://fonts.googleapis.com/css?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<body>\n  <h1>%s</h1>\n", new_title, new_title);
		fprintf(course, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"course.html\">Home</a></li>\n   <li id=\"nav-li\"><a href=\"syll.html\">Syllabus</a></li>\n   <li id=\"nav-li\"><a href=\"sched.html\">Schedule</a></li>\n   <li id=\"nav-li\"><a href=\"res.html\">Resources</a></li>\n  </ul>\n  <div>\n  \t<h3>Description</h3>\n  \t<p>My description.</p>\n  </div>\n</body>\n</html>");
		fclose(course);

		syll= fopen("site/syll.html", "w"); 
		fprintf(syll, "<!-- Syllabus -->\n<!DOCTYPE html>\n<html>\n<head>\n  <title>%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" href=\"theme.css\">\n  <link href=\"https://fonts.googleapis.com/css?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<body>\n  <h1>%s</h1>\n", new_title, new_title);
		fprintf(syll, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"course.html\">Home</a></li>\n   <li id=\"nav-li\"><a href=\"syll.html\">Syllabus</a></li>\n   <li id=\"nav-li\"><a href=\"sched.html\">Schedule</a></li>\n   <li id=\"nav-li\"><a href=\"res.html\">Resources</a></li>\n  </ul>\n  <div>\n  \t<h3>Instructor</h3>\n  \t<h3>Topics</h3>\n    <h3>Grading</h3>\n    <h3>Policies</h3>\n  </div>\n</body>\n</html>");
		fclose(syll);

		sched = fopen("site/sched.html", "w");
		fprintf(sched, "<!-- Schedule -->\n<!DOCTYPE html>\n<html>\n<head>\n  <title>%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" href=\"site/theme.css\">\n  <link href=\"https://fonts.googleapis.com/css?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<body>\n  <h1>%s</h1>\n", new_title, new_title);
		fprintf(sched, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"course.html\">Home</a></li>\n   <li id=\"nav-li\"><a href=\"syll.html\">Syllabus</a></li>\n   <li id=\"nav-li\"><a href=\"sched.html\">Schedule</a></li>\n   <li id=\"nav-li\"><a href=\"res.html\">Resources</a></li>\n  </ul>\n  <div>\n    <h3>Tentative Schedule</h3>\n    <table>\n    <tr>\n      <th>Date</th>\n      <th>Topic</th>\n    </tr>\n    <tr>\n      <td>Date 1</td>\n      <td>Topic 1</td>\n    </tr>\n    </table>\n  </br>\n  </div>\n</body>\n</html>");
		fclose(sched);

		res = fopen("site/res.html", "w");
		fprintf(res, "<!-- Resources -->\n<!DOCTYPE html>\n<html>\n<head>\n  <title>%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" href=\"site/theme.css\">\n  <link href=\"https://fonts.googleapis.com/css?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<body>\n  <h1>%s</h1>\n", new_title, new_title);
		fprintf(res, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"course.html\">Home</a></li>\n   <li id=\"nav-li\"><a href=\"syll.html\">Syllabus</a></li>\n   <li id=\"nav-li\"><a href=\"sched.html\">Schedule</a></li>\n   <li id=\"nav-li\"><a href=\"res.html\">Resources</a></li>\n  </ul>\n  <div>\n  \t<p>Course resources.</p>\n  </div>\n</body>\n</html>");
		fclose(res);		
	}

	if (theme == 1) {
		html_c = "#ffffff";
		nav_c = "#b3b3b3";
		div_c = "#dddddd";
	} else if (theme == 2) {
		html_c = "#99ccff";
		nav_c = "#3b33ff";
		div_c = "#3391ff";
	} else if (theme == 3) {
		html_c = "#f63c3c";
		nav_c = "#ff9900";
		div_c = "#d5d50a";
	} else if (theme == 4) {
		html_c = "#ffc266";
		nav_c = "#afb315";
		div_c = "#60b315";
	} else if (theme == 5) {
		html_c = "#15b32a";
		nav_c = "#006600";
		div_c = "#159eb3";
	} 

	if (format == 1) {
		padding = "5px";
		nav_f = "display: flex;\n  justify-content: space-around;\n";
		nav_li = "inline-block;\n";
		div_f = "";
	} else if (format == 2) {
		padding = "25px";
		nav_f = "float: left;\n"; 
		nav_li = "block;\n";
		div_f = "\n\tfloat: right;\n  width: 80%;\n";
	}

	printf("Your site has been generated in the directory \"site\".\n");		

	css = fopen("site/theme.css", "w");
	fprintf(css,"/* Default options for color and menu. */\nhtml {\n  font-family: 'Open Sans', sans-serif;\n  margin: 2%%;\n  background-color: %s; \n}\n\nul {\n  list-style-type: none;\n}\n\n#nav { \n  padding: %s; \n  margin: 0;\n  overflow: hidden;\n  background-color: %s; \n  text-align: center;\n  font-size: 18px;\n  %s\n}\n\n#nav-li {\n  display: %s \n}\n\nli a {\n  text-decoration: none;\n  padding: 5px;  \n}\n\n", html_c, padding, nav_c, nav_f, nav_li);
	fprintf(css,"li a:visited {\n  color: black;\n}\n\nli a:hover {\n  color: white;\n}\n\ndiv {\n  background-color: %s;\n  padding-left: 10px;\n  padding-top: 2px;\n  padding-bottom: 2px;\n  font-size: 20px;%s\n}\n\ntable {\n  border-collapse: collapse;\n  width: 90%%;\n  margin-left: auto;\n  margin-right: auto;\n  float: none;\n}\n\nth {\n  background: gray;\n}\n\ntd {\n  background: white;\n}\n\ntd, th {\n  border: 1px solid #000000;\n  text-align: left;\n  padding: 8px;\n}", div_c, div_f); 
	fclose(css);

	free(title);
	free(c_type);
	free(c_theme);
	free(c_format);

	return 0;
}
