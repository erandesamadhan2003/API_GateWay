CREATE TABLE
    IF NOT EXISTS request_logs (
        id BIGSERIAL PRIMARY KEY,
        ip_address INET,
        method VARCHAR(10) NOT NULL,
        endpoint TEXT NOT NULL,
        status_code INTEGER NOT NULL,
        latency_ms INTEGER NOT NULL,
        user_id INTEGER,
        created_at TIMESTAMPTZ DEFAULT NOW (),
        CONSTRAINT fk_logs_user FOREIGN KEY (user_id) REFERENCES users (id) ON DELETE SET NULL
    );

-- Indexes
CREATE INDEX IF NOT EXISTS idx_logs_created_at ON request_logs (created_at);
CREATE INDEX IF NOT EXISTS idx_logs_status_code ON request_logs (status_code);
CREATE INDEX IF NOT EXISTS idx_logs_user_id ON request_logs (user_id);
CREATE INDEX IF NOT EXISTS idx_logs_endpoint ON request_logs (endpoint);