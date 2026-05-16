#!/bin/bash

psql -U samadhan -d api_gateway -f ../migrations/001_create_users.sql
psql -U samadhan -d api_gateway -f ../migrations/002_create_products_orders.sql
psql -U samadhan -d api_gateway -f ../migrations/003_create_logs.sql