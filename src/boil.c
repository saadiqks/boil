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
		printf("Enter the number of your color theme (Default - 1) (Sky - 2) (Lava"); 
		printf("- 3) (Pumpkin - 4) (Forest - 5): ");
		if (fgets(buffer, MAX_LEN, stdin))
  		asprintf(&c_theme, "%s", buffer);
  	theme = atoi(c_theme);
	}

	while (format != 1 && format != 2) {
		printf("Enter the number of your formatting (Default - 1) (Sidemenu - 2): ");
		if (fgets(buffer, MAX_LEN, stdin))
  		asprintf(&c_format, "%s", buffer);
  	format = atoi(c_format);
	}

	if (type == 1) {
		blog = fopen("site/blog.html", "w");
		fprintf(blog, "<!-- Blog. -->\n<!DOCTYPE html>\n<html>\n<head>\n  <title>%s", new_title);
		fprintf(blog, "</title>\n  <link rel=\"stylesheet\" type=\"text/css\" href=");
		fprintf(blog, "\"theme.css\">\n  <link href=\"https://fonts.googleapis.com/");
		fprintf(blog, "css?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<body>");
		fprintf(blog, "\n  <h1>%s</h1>\n", new_title);
		fprintf(blog, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"blog.html");
		fprintf(blog, "\">Home</a></li>\n   <li id=\"nav-li\"><a href =\"archive.ht");
		fprintf(blog, "ml\">Archive</a></li>\n   <li id=\"nav-li\"><a href =\"about");
		fprintf(blog, ".html\">About</a></li>\n  </ul>\n  <div>\n  \t<h3>January 1<");
		fprintf(blog, "/h3>\n  \t<p>My first post.</p>\n  </div>\n</body>\n</html>\n");
		fclose(blog);		

		archive = fopen("site/archive.html", "w");
		fprintf(archive, "<!-- Archive. -->\n<!DOCTYPE html>\n<html>\n<head>\n  <ti");
		fprintf(archive, "tle>%s</title>\n  <link rel=\"stylesheet\" type=\"text/cs", new_title);
		fprintf(archive, "s\" href=\"theme.css\">\n  <link href=\"https://fonts.goo");
		fprintf(archive, "gleapis.com/css?family=Open+Sans\" rel=\"stylesheet\">\n<");
		fprintf(archive, "/head>\n<body>\n\t<h1>%s</h1>\n", new_title);
		fprintf(archive, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href =\"blog.h");
		fprintf(archive, "tml\">Home</a></li>\n   <li id=\"nav-li\"><a href =\"arch");
		fprintf(archive, "ive.html\">Archive</a></li>\n   <li id=\"nav-li\"><a href");
		fprintf(archive, "=\"about.html\">About</a></li>\n  </ul>\n  <div>\n  \t<ul");
		fprintf(archive, ">\n      <l1>Previous Post 1</l1>\n      <li>Previous Pos");
		fprintf(archive, "t 2</li>\n    </ul>\n  <div>\n</body>\n</html>\n");
		fclose(archive);

		about = fopen("site/about.html", "w");
		fprintf(about, "<!-- About. -->\n<!DOCTYPE html>\n<html>\n<head>\n  <title>");
		fprintf(about, "%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" hr", new_title);
		fprintf(about, "ef=\"theme.css\">\n  <link href=\"https://fonts.googleapis.");
		fprintf(about, "com/css?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<b");
		fprintf(about, "ody>\n\t<h1>%s</h1>\n", new_title);
		fprintf(about, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"blog.html");
		fprintf(about, "\">Home</a></li>\n   <li id=\"nav-li\"><a href=\"archive.ht");
		fprintf(about, "ml\">Archive</a></li>\n   <li id=\"nav-li\"><a href=\"about");
		fprintf(about, ".html\">About</a></li>\n  </ul>\n  <div>\n  \t<p>My descrip");
		fprintf(about, "tion.</p>\n  <div>\n</body>\n</html>");
		fclose(about);		
	} else if (type == 2) {
		port = fopen("site/port.html", "w");
		fprintf(port, "<!-- Portfolio. -->\n<!DOCTYPE html>\n<head>\n  <title>%s</t", new_title);
		fprintf(port, "itle>\n  <link rel=\"stylesheet\" type=\"text/css\" href=\"t");
		fprintf(port, "heme.css\">\n  <link href=\"https://fonts.googleapis.com/css");
		fprintf(port, "?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<body>\n\t");
		fprintf(port, "<h1>%s</h1>\n  ", new_title);
		fprintf(port, "<ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"port.html\">");
		fprintf(port, "Home</a></li>\n   <li id=\"nav-li\"><a href=\"proj.html\">Pr");
		fprintf(port, "ojects</a></li>\n   <li id=\"nav-li\">Resume</li> <!-- Link"); 
		fprintf(port, "to PDF. -->\n   <li id=\"nav-li\">CV</li> <!-- Link to PDF. ");
		fprintf(port, "-->\n  </ul>\n  <div>\n    <h3>About Me</h3>\n    <p>My desc");
		fprintf(port, "ription.</p>\n  </div>\n</body>\n</html>");
		fclose(port); 	

		proj = fopen("site/proj.html", "w");
		fprintf(proj, "<!-- Portfolio. -->\n<!DOCTYPE html>\n<head>\n  <title>%s</t", new_title);
		fprintf(proj, "itle>\n  <link rel=\"stylesheet\" type=\"text/css\" href=\"t");
		fprintf(proj, "heme.css\">\n  <link href=\"https://fonts.googleapis.com/css");
		fprintf(proj, "?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<body>\n\t");
		fprintf(proj, "<h1>%s</h1>\n  ", new_title);
		fprintf(proj, "<ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"port.html\">");
		fprintf(proj, "Home</a></li>\n   <li id=\"nav-li\"><a href=\"proj.html\">Pr");
		fprintf(proj, "ojects</a></li>\n   <li id=\"nav-li\">Resume</li> <!-- Link ");
		fprintf(proj, "to PDF. -->\n   <li id=\"nav-li\">CV</li> <!-- Link to PDF. ");
		fprintf(proj, "-->\n  </ul>\n  <div>\n    <h3>Project 1</h3>\n    <p>My des");
		fprintf(proj, "cription.</p>\n    <h3>Project 2</h3>\n    <p>My description");
		fprintf(proj, ".</p>\n  </div>\n</body>\n</html>");
	} else if (type == 3) {
		course = fopen("site/course.html", "w");
		fprintf(course, "<!-- Course -->\n<!DOCTYPE html>\n<html>\n<head>\n  <title");
		fprintf(course, ">%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" ", new_title); 
		fprintf(course, "href=\"theme.css\">\n  <link href=\"https://fonts.googleap");
		fprintf(course, "is.com/css?family=Open+Sans\" rel=\"stylesheet\">\n</head>");
		fprintf(course, "\n<body>\n  <h1>%s</h1>\n", new_title);
		fprintf(course, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"course.h");
		fprintf(course, "tml\">Home</a></li>\n   <li id=\"nav-li\"><a href=\"syll.h");
		fprintf(course, "tml\">Syllabus</a></li>\n   <li id=\"nav-li\"><a href=\"sc");
		fprintf(course, "hed.html\">Schedule</a></li>\n   <li id=\"nav-li\"><a href");
		fprintf(course, "=\"res.html\">Resources</a></li>\n  </ul>\n  <div>\n  \t<h");
		fprintf(course, "3>Description</h3>\n  \t<p>My description.</p>\n  </div>\n");
		fprintf(course, "</body>\n</html>");
		fclose(course);

		syll= fopen("site/syll.html", "w"); 
		fprintf(syll, "<!-- Syllabus -->\n<!DOCTYPE html>\n<html>\n<head>\n  <title");
		fprintf(syll, ">%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" hr", new_title);
		fprintf(syll, "ef=\"theme.css\">\n  <link href=\"https://fonts.googleapis.c");
		fprintf(syll, "om/css?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<bod");
		fprintf(syll, "y>\n  <h1>%s</h1>\n", new_title);
		fprintf(syll, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"course.htm");
		fprintf(syll, "l\">Home</a></li>\n   <li id=\"nav-li\"><a href=\"syll.html");
		fprintf(syll, "\">Syllabus</a></li>\n   <li id=\"nav-li\"><a href=\"sched.h");
		fprintf(syll, "tml\">Schedule</a></li>\n   <li id=\"nav-li\"><a href=\"res.");
		fprintf(syll, "html\">Resources</a></li>\n  </ul>\n  <div>\n  \t<h3>Instruc");
		fprintf(syll, "tor</h3>\n  \t<h3>Topics</h3>\n    <h3>Grading</h3>\n    <h3");
		fprintf(syll, ">Policies</h3>\n  </div>\n</body>\n</html>");
		fclose(syll);

		sched = fopen("site/sched.html", "w");
		fprintf(sched, "<!-- Schedule -->\n<!DOCTYPE html>\n<html>\n<head>\n  <titl");
		fprintf(sched, "e>%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" ", new_title);
		fprintf(sched, "href=\"site/theme.css\">\n  <link href=\"https://fonts.goog");
		fprintf(sched, "leapis.com/css?family=Open+Sans\" rel=\"stylesheet\">\n</he");
		fprintf(sched, "ad>\n<body>\n  <h1>%s</h1>\n", new_title);
		fprintf(sched, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"course.ht");
		fprintf(sched, "ml\">Home</a></li>\n   <li id=\"nav-li\"><a href=\"syll.htm");
		fprintf(sched, "l\">Syllabus</a></li>\n   <li id=\"nav-li\"><a href=\"sched");
		fprintf(sched, ".html\">Schedule</a></li>\n   <li id=\"nav-li\"><a href=\"r");
		fprintf(sched, "es.html\">Resources</a></li>\n  </ul>\n  <div>\n    <h3>Ten");
		fprintf(sched, "tative Schedule</h3>\n    <table>\n    <tr>\n      <th>Date");
		fprintf(sched, "</th>\n      <th>Topic</th>\n    </tr>\n    <tr>\n      <td");
		fprintf(sched, ">Date 1</td>\n      <td>Topic 1</td>\n    </tr>\n    </tabl");
		fprintf(sched, "e>\n  </br>\n  </div>\n</body>\n</html>");
		fclose(sched);

		res = fopen("site/res.html", "w");
		fprintf(res, "<!-- Resources -->\n<!DOCTYPE html>\n<html>\n<head>\n  <title");
		fprintf(res, ">%s</title>\n  <link rel=\"stylesheet\" type=\"text/css\" hre", new_title);
		fprintf(res, "f=\"site/theme.css\">\n  <link href=\"https://fonts.googleapi");
		fprintf(res, "s.com/css?family=Open+Sans\" rel=\"stylesheet\">\n</head>\n<b");
		fprintf(res, "ody>\n  <h1>%s</h1>\n", new_title);
		fprintf(res, "  <ul id=\"nav\">\n   <li id=\"nav-li\"><a href=\"course.html");
		fprintf(res, "\">Home</a></li>\n   <li id=\"nav-li\"><a href=\"syll.html\">");
		fprintf(res, "Syllabus</a></li>\n   <li id=\"nav-li\"><a href=\"sched.html");
		fprintf(res, "\">Schedule</a></li>\n   <li id=\"nav-li\"><a href=\"res.html");
		fprintf(res, "\">Resources</a></li>\n  </ul>\n  <div>\n  \t<p>Course resour");
		fprintf(res, "ces.</p>\n  </div>\n</body>\n</html>");
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
	fprintf(css,"/* Default options for color and menu. */\nhtml {\n  font-family");
	fprintf(css,": 'Open Sans', sans-serif;\n  margin: 2%%;\n  background-color: ");
	fprintf(css, "%s; \n}\n\nul {\n  list-style-type: none;\n}\n\n#nav { \n  padd", html_c);
	fprintf(css, "ing: %s; \n  margin: 0;\n  overflow: hidden;\n  background-colo", padding);
	fprintf(css, "r: %s; \n  text-align: center;\n  font-size: 18px;\n  %s\n}\n\n", nav_c, nav_f);
	fprintf(css, "#nav-li {\n  display: %s \n}\n\nli a {\n  text-decoration: none", nav_li);
	fprintf(css, ";\n  padding: 5px;  \n}\n\n");
	fprintf(css,"li a:visited {\n  color: black;\n}\n\nli a:hover {\n  color: whi");
	fprintf(css, "te;\n}\n\ndiv {\n  background-color: %s;\n  padding-left: 10px;", div_c);
	fprintf(css, "\n  padding-top: 2px;\n  padding-bottom: 2px;\n  font-size: 20p");
	fprintf(css, "x;%s\n}\n\ntable {\n  border-collapse: collapse;\n  width: 90%%", div_f);
	fprintf(css,";\n  margin-left: auto;\n  margin-right: auto;\n  float: none;\n");
  fprintf(css, "}\n\nth {\n  background: gray;\n}\n\ntd {\n  background: white;");
  fprintf(css, "\n}\n\ntd, th {\n  border: 1px solid #000000;\n  text-align: le");
  fprintf(css, "ft;\n  padding: 8px;\n}"); 
	fclose(css);

	free(title);
	free(c_type);
	free(c_theme);
	free(c_format);

	return 0;
}