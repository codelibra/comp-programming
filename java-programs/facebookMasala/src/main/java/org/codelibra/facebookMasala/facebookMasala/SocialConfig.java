package org.codelibra.facebookMasala.facebookMasala;

import org.springframework.context.annotation.Configuration;
import org.springframework.core.env.Environment;
import org.springframework.social.UserIdSource;
import org.springframework.social.config.annotation.ConnectionFactoryConfigurer;
import org.springframework.social.config.annotation.SocialConfigurer;
import org.springframework.social.connect.ConnectionFactoryLocator;
import org.springframework.social.connect.UsersConnectionRepository;
import org.springframework.social.facebook.connect.FacebookConnectionFactory;

@Configuration
public class SocialConfig implements SocialConfigurer {

    public UserIdSource getUserIdSource() {
        // TODO Auto-generated method stub
        return null;
    }

    public UsersConnectionRepository getUsersConnectionRepository(ConnectionFactoryLocator arg0) {
        // TODO Auto-generated method stub
        return null;
    }
    
    public void addConnectionFactories(ConnectionFactoryConfigurer cfConfig, Environment env) {
        cfConfig.addConnectionFactory(new FacebookConnectionFactory(env.getProperty("958303810850960"), env
                .getProperty("ca672e41fbee1665a92fb3198988cf55")));
    }

}