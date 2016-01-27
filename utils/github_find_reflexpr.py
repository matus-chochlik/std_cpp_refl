#!/usr/bin/python

dict_dump = "word_dict.pyo";
dict_text = "word_dict.txt";

def query_repos(page):
	import json, urllib2
	return json.load(urllib2.urlopen("https://api.github.com/search/repositories?q=language:cpp&page=%d" % page))

def process_file(words, full_path):
	import re

	try:
		for line in open(full_path):
			for word in re.findall(r"\b[^\d\W]\w*\b", line):
				words[word] = words.get(word, 0)+1
	except IOError: pass
	return words

def search_repo(page, repo_url, repo_dir, words):
	import os, fnmatch

	for root, dirs, files in os.walk(repo_dir):
		for name in files:
			full_path = os.path.join(root, name)
			for ext in ['cpp','hpp','ipp','inl','c','h']:
				if fnmatch.fnmatch(full_path, "*."+ext):
					process_file(words, full_path)


def load_word_dict(page, repo_url):
	import pickle, shutil

	try:
		word_dict = pickle.load(open(dict_dump))
		shutil.copyfile(dict_dump, dict_dump+".bak")
	except IOError:
		word_dict = dict()
		word_dict["words"] = dict()

	word_dict["page"] = page
	word_dict["repos"] = word_dict.get("repos", 0)+1

	return word_dict

def save_word_dict(word_dict):
	import pickle, shutil

	pickle.dump(word_dict, open(dict_dump, 'w'))
	open(dict_text, "wt").write(str(word_dict))


def process_repo(page, repo_url):
	import tempfile, shutil, subprocess

	temp_dir = tempfile.mkdtemp()

	try:
		cmdline = ['git', 'clone', repo_url, temp_dir]
		subprocess.call(cmdline)

		word_dict = load_word_dict(page, repo_url)

		search_repo(page, repo_url, temp_dir, word_dict["words"])

		save_word_dict(word_dict)

		shutil.rmtree(temp_dir)
	except:
		shutil.rmtree(temp_dir)
		raise

def process_repos(page, repos):
	for repo in repos:
		if not repo["fork"]:
			process_repo(page, repo["clone_url"])


def process_all():
	import time

	query_delay = 500
	prev_req_time = 0.0
	page = 0

	while True:
		while True:
			delay = query_delay - time.time() + prev_req_time
			if delay <= 0: break
			time.sleep(delay)

		prev_req_time = time.time()
		page += 1

		response = query_repos(page)
		process_repos(page, response["items"])

process_all()
