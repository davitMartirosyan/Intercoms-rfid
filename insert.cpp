inter_id.push_back(24);
        rf_id.push_back(3586486);
        card_id.push_back(2214456464);
        fname.push_back("Davit");
        lname.push_back("Martirosyan");

        sql::Driver *driver = get_driver_instance();
        sql::Connection *con =  driver->connect(HOST, USER, PASS);
        con->setSchema(DB);
        
        std::unique_ptr<sql::PreparedStatement> pstmt;
        pstmt.reset(con->prepareStatement("INSERT INTO users (inter_id, rf_id, card_id, fname, lname) VALUES(?,?,?,?,?)"));
        pstmt->setInt(1, inter_id[0]);
        pstmt->setInt(2, rf_id[0]);
        pstmt->setInt(3, card_id[0]);
        pstmt->setString(4, fname[0]);
        pstmt->setString(5, lname[0]);
        pstmt->execute();