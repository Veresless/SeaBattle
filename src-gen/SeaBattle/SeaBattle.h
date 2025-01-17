/*
 * Autogenerated by ThriftMeGenerator (v2.13.4.0)
 * 
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING!
 * 
 * Copyright 2020 Daimler AG
 * All Rights Reserved.
 * NOTICE:  All added/modified information contained herein is and remains the proprietary of Daimler AG.
 * The intellectual and technical concepts contained herein are proprietary to Daimler AG and may be covered by German and Foreign Patents, patent applications, and are protected by trade secret or copyright law.
 */

#ifndef _SEABATTLE_SEABATTLE_
#define _SEABATTLE_SEABATTLE_

#include <platform/Platform.h>
#include <TAsyncResult.h>
#include <TCallContext.h>
#include <TDeferredResponse.h>
#include <TClient.h>
#include <TServiceProcessor.h>
#include <transport/TTransport.h>
#include <transport/TMessageBuffer.h>
#include <TServiceReference.h>
#include <utility/TToolbox.h>
#include <utility/THashUtils.h>
#include <gate/TMessageGate.h>

#include "ShootRezult.h"

#if defined(_MSC_VER)
#pragma warning ( push )
#pragma warning ( disable : 4250 )
#endif

namespace SeaBattle
{

	namespace SeaBattleFunctionIds
	{
		/** Function ID for oponentConectedEvent */
		static const int32_t OPONENT_CONECTED_EVENT_ID = -887460521;
		/** Function ID for oponentShootEvent */
		static const int32_t OPONENT_SHOOT_EVENT_ID = -1432837523;
		/** Function ID for setShootResponse */
		static const int32_t SET_SHOOT_RESPONSE_ID = -1616261951;
		/** Function ID for setShoot */
		static const int32_t SET_SHOOT_ID = 1176340222;
		/** Function ID for shootResponseEvent */
		static const int32_t SHOOT_RESPONSE_EVENT_ID = -259993043;
		/** Function ID for gameOver */
		static const int32_t GAME_OVER_ID = -1870162115;
		/** Function ID for subscribe */
		static const int32_t SUBSCRIBE_ID = -1348580861;
		/** Function ID for unsubscribe */
		static const int32_t UNSUBSCRIBE_ID = -104923498;
	};

	/** Some information relevant for analysis of the server type. */
	namespace ServiceIds
	{
		/** Service name hash value for SeaBattle (not the server/deployment ID!) */
		static const int32_t SEA_BATTLE_ID = 865928165;
		static const ::thrift::TServiceDescriptor& getSeaBattleVersion() { static const ::thrift::TServiceDescriptor apiVersion("SeaBattle.SeaBattle", "0.0"); return apiVersion; }
	}
	namespace SeaBattleParameters
	{
		typedef /* /OUT */ ::thrift::utility::toolbox::void_result setShootResponse_result;
		typedef /* /OUT */ ::thrift::utility::toolbox::void_result setShoot_result;
		typedef /* /OUT */ ::thrift::utility::toolbox::void_result subscribe_result;
		typedef /* /OUT */ ::thrift::utility::toolbox::void_result unsubscribe_result;
	}
	/**
	 * @version 0.0
	 */
	class ISeaBattleEventDispatcher
	{
		public:
			virtual ~ISeaBattleEventDispatcher() { }
			/**
			 * @param topicId The topic ID under which this event will be published. If the topic ID is 0 the event will be distributed to all clients. Otherwise it will be distributed by all multicast transports and all transports which are subscribed on the topic ID.
			 */
			virtual void oponentConectedEvent(const int16_t clientID,
				const int32_t topicId = 0) = 0;
			/**
			 * @param topicId The topic ID under which this event will be published. If the topic ID is 0 the event will be distributed to all clients. Otherwise it will be distributed by all multicast transports and all transports which are subscribed on the topic ID.
			 */
			virtual void oponentShootEvent(const int32_t x,
				const int32_t y,
				const int16_t clientID,
				const int32_t topicId = 0) = 0;
			/**
			 * @param topicId The topic ID under which this event will be published. If the topic ID is 0 the event will be distributed to all clients. Otherwise it will be distributed by all multicast transports and all transports which are subscribed on the topic ID.
			 */
			virtual void shootResponseEvent(const ::SeaBattle::ShootRezult::type& rezult,
				const int16_t clientID,
				const int32_t topicId = 0) = 0;
			/**
			 * @param topicId The topic ID under which this event will be published. If the topic ID is 0 the event will be distributed to all clients. Otherwise it will be distributed by all multicast transports and all transports which are subscribed on the topic ID.
			 */
			virtual void gameOver(const bool rezult,
				const int16_t clientID,
				const int32_t topicId = 0) = 0;
	};

	/**
	 * @version 0.0
	 */
	class ISeaBattleServer
	{
		public:
			virtual ~ISeaBattleServer() { }
			/**
			 * Returns a descriptor for the service, which contains the full qualified typename and version of the service
			 * @param context Information about the context of the function call
			 */
			virtual ::thrift::TServiceDescriptor getServiceDescriptor(const ::thrift::transport::TCallContext& context) = 0;
			/**
			 * @param context Information about the context of the function call
			 */
			virtual void setShootResponse(const ::SeaBattle::ShootRezult::type& rezult,
				const int16_t clientID,
				const ::thrift::transport::TCallContext& context) = 0;
			/**
			 * @param context Information about the context of the function call
			 */
			virtual void setShoot(const int32_t x,
				const int32_t y,
				const int16_t clientID,
				const ::thrift::transport::TCallContext& context) = 0;
			/**
			 * @param context Information about the context of the function call
			 */
			virtual void subscribe(const int16_t clientID,
				const ::thrift::transport::TCallContext& context) = 0;
			/**
			 * @param context Information about the context of the function call
			 */
			virtual void unsubscribe(const int16_t clientID,
				const ::thrift::transport::TCallContext& context) = 0;
	};

	/**
	 * @version 0.0
	 */
	class SeaBattleProcessor : public ::thrift::TServiceProcessor, public virtual ISeaBattleEventDispatcher, public virtual ISeaBattleServer
	{
		public:
			SeaBattleProcessor(const std::shared_ptr< ::thrift::TServiceBroker >& broker, const std::shared_ptr< ::thrift::locks::ILockable >& lockable = std::shared_ptr< ::thrift::locks::ILockable >());

		protected:
			TM_DECL_LOCAL void process_getServiceDescriptor(int seqId, int32_t serviceId, int32_t exFlags, const ::thrift::TCallContext& context, const std::shared_ptr< ::thrift::transport::TMessageBuffer >& message);
			TM_DECL_LOCAL void process_setShootResponse(int seqId, int32_t serviceId, int32_t exFlags, const ::thrift::TCallContext& context, const std::shared_ptr< ::thrift::transport::TMessageBuffer >& message);
			TM_DECL_LOCAL void process_setShoot(int seqId, int32_t serviceId, int32_t exFlags, const ::thrift::TCallContext& context, const std::shared_ptr< ::thrift::transport::TMessageBuffer >& message);
			TM_DECL_LOCAL void process_subscribe(int seqId, int32_t serviceId, int32_t exFlags, const ::thrift::TCallContext& context, const std::shared_ptr< ::thrift::transport::TMessageBuffer >& message);
			TM_DECL_LOCAL void process_unsubscribe(int seqId, int32_t serviceId, int32_t exFlags, const ::thrift::TCallContext& context, const std::shared_ptr< ::thrift::transport::TMessageBuffer >& message);
			public:
			static const inline ::thrift::TServiceDescriptor& getServiceDescriptor() { return ServiceIds::getSeaBattleVersion(); }
			protected:
			virtual ::thrift::TServiceDescriptor getServiceDescriptor(const ::thrift::transport::TCallContext& /*context*/) TM_CXXLANG_OVERRIDE
			{
				return ServiceIds::getSeaBattleVersion();
			}

		public:
			virtual ~SeaBattleProcessor() {}

			/**
			 * @param topicId The topic ID under which this event will be published. If the topic ID is 0 the event will be distributed to all clients. Otherwise it will be distributed by all multicast transports and all transports which are subscribed on the topic ID.
			 */
			virtual void oponentConectedEvent(const int16_t clientID,
				const int32_t topicId = 0) TM_CXXLANG_OVERRIDE;
			/**
			 * @param topicId The topic ID under which this event will be published. If the topic ID is 0 the event will be distributed to all clients. Otherwise it will be distributed by all multicast transports and all transports which are subscribed on the topic ID.
			 */
			virtual void oponentShootEvent(const int32_t x,
				const int32_t y,
				const int16_t clientID,
				const int32_t topicId = 0) TM_CXXLANG_OVERRIDE;
			/**
			 * @param topicId The topic ID under which this event will be published. If the topic ID is 0 the event will be distributed to all clients. Otherwise it will be distributed by all multicast transports and all transports which are subscribed on the topic ID.
			 */
			virtual void shootResponseEvent(const ::SeaBattle::ShootRezult::type& rezult,
				const int16_t clientID,
				const int32_t topicId = 0) TM_CXXLANG_OVERRIDE;
			/**
			 * @param topicId The topic ID under which this event will be published. If the topic ID is 0 the event will be distributed to all clients. Otherwise it will be distributed by all multicast transports and all transports which are subscribed on the topic ID.
			 */
			virtual void gameOver(const bool rezult,
				const int16_t clientID,
				const int32_t topicId = 0) TM_CXXLANG_OVERRIDE;

	};

	/**
	 * @version 0.0
	 */
	class ISeaBattleClient
	{
		public:
			virtual ~ISeaBattleClient() { }
			virtual void setShootResponse(const ::SeaBattle::ShootRezult::type& rezult,
				const int16_t clientID) = 0;
			virtual void setShoot(const int32_t x,
				const int32_t y,
				const int16_t clientID) = 0;
			virtual void subscribe(const int16_t clientID) = 0;
			virtual void unsubscribe(const int16_t clientID) = 0;
	};

	/**
	 * @version 0.0
	 */
	class ISeaBattleEventReceiver
	{
		public:
			virtual ~ISeaBattleEventReceiver() { }
			virtual void oponentConectedEvent(const int16_t clientID) = 0;
			virtual void oponentShootEvent(const int32_t x,
				const int32_t y,
				const int16_t clientID) = 0;
			virtual void shootResponseEvent(const ::SeaBattle::ShootRezult::type& rezult,
				const int16_t clientID) = 0;
			virtual void gameOver(const bool rezult,
				const int16_t clientID) = 0;
	};

	/**
	 * @version 0.0
	 */
	class SeaBattleClient : public ::thrift::TClient, public virtual ISeaBattleClient, public virtual ISeaBattleEventReceiver
	{
		public:
			/** Hint: C++11 users can use simple constructor inheritance here */
			SeaBattleClient(const std::shared_ptr< ::thrift::TServiceBroker >& broker,
				const std::string& address,
				const std::shared_ptr< ::thrift::locks::ILockable >& lockable,
				const ::thrift::utility::TOptionContainer& transportOptions = ::thrift::utility::TOptionContainer());

			virtual ~SeaBattleClient() {}

			typedef ::thrift::utility::TClientSpecificFactory<SeaBattleClient, ::thrift::utility::TClientFactory> Factory;

			static std::shared_ptr< SeaBattleClient > createClient(const std::shared_ptr< ::thrift::TServiceBroker >& broker, const std::string& address, const SeaBattleClient::Factory& factory, const std::shared_ptr< ::thrift::locks::ILockable >& lockable = std::shared_ptr< ::thrift::locks::ILockable >());
			inline static std::shared_ptr< SeaBattleClient > createClient(const std::shared_ptr< ::thrift::TServiceBroker >& broker, const std::string& address, const std::shared_ptr< ::thrift::locks::ILockable >& lockable = std::shared_ptr< ::thrift::locks::ILockable >())
			{
				return createClient(broker, address, SeaBattleClient::Factory(), lockable);
			}
			static std::shared_ptr< SeaBattleClient > createClient(const std::shared_ptr< ::thrift::TServiceBroker >& broker, const ::thrift::TServiceReference& serviceReference, const SeaBattleClient::Factory& factory, const std::shared_ptr< ::thrift::locks::ILockable >& lockable = std::shared_ptr< ::thrift::locks::ILockable >());
			inline static std::shared_ptr< SeaBattleClient > createClient(const std::shared_ptr< ::thrift::TServiceBroker >& broker, const ::thrift::TServiceReference& serviceReference, const std::shared_ptr< ::thrift::locks::ILockable >& lockable = std::shared_ptr< ::thrift::locks::ILockable >())
			{
				return createClient(broker, serviceReference, SeaBattleClient::Factory(), lockable);
			}

			template<class IMPCLASS>
			static inline std::shared_ptr<IMPCLASS> createClient(const std::shared_ptr< ::thrift::TServiceBroker >& broker, const std::string& address,
				const std::shared_ptr< ::thrift::locks::ILockable >& lockable = std::shared_ptr< ::thrift::locks::ILockable >())
			{
				::thrift::utility::TUri uri(address);
				return ::thrift::TClient::createClient<IMPCLASS>(broker, address, ::thrift::utility::TClientSpecificFactory<IMPCLASS, ::thrift::utility::TClientFactory>(), lockable);
			}
			/**
			 * Returns true if the client is connected to the server and the clients and servers service types are matching. Otherwise false will be returned.
			 */
			virtual bool verifyClient();

			/** Access to API version information */
			const ::thrift::TServiceDescriptor& getClientVersion() const TM_CXXLANG_OVERRIDE { return ServiceIds::getSeaBattleVersion(); }

		protected:
			TM_DECL_LOCAL void process_oponentConectedEvent(int seqId, int32_t serviceId, int32_t exFlags, const ::thrift::TCallContext& context, const std::shared_ptr< ::thrift::transport::TMessageBuffer >& message);
			virtual void oponentConectedEvent(const int16_t clientID) TM_CXXLANG_OVERRIDE;

			TM_DECL_LOCAL void process_oponentShootEvent(int seqId, int32_t serviceId, int32_t exFlags, const ::thrift::TCallContext& context, const std::shared_ptr< ::thrift::transport::TMessageBuffer >& message);
			virtual void oponentShootEvent(const int32_t x,
				const int32_t y,
				const int16_t clientID) TM_CXXLANG_OVERRIDE;

			TM_DECL_LOCAL void process_shootResponseEvent(int seqId, int32_t serviceId, int32_t exFlags, const ::thrift::TCallContext& context, const std::shared_ptr< ::thrift::transport::TMessageBuffer >& message);
			virtual void shootResponseEvent(const ::SeaBattle::ShootRezult::type& rezult,
				const int16_t clientID) TM_CXXLANG_OVERRIDE;

			TM_DECL_LOCAL void process_gameOver(int seqId, int32_t serviceId, int32_t exFlags, const ::thrift::TCallContext& context, const std::shared_ptr< ::thrift::transport::TMessageBuffer >& message);
			virtual void gameOver(const bool rezult,
				const int16_t clientID) TM_CXXLANG_OVERRIDE;


		public:
			typedef ::thrift::TSpecificAsyncResult< ::thrift::TAsyncResult::SuccessCallback, SeaBattleParameters::setShootResponse_result, void > setShootResponse_AsyncResult;
			typedef ::thrift::TCompletableSpecificAsyncResult< ::thrift::TAsyncResult::SuccessCallback, SeaBattleParameters::setShootResponse_result, void > setShootResponse_CompletableAsyncResult;
			virtual void setShootResponse(const ::SeaBattle::ShootRezult::type& rezult,
				const int16_t clientID) TM_CXXLANG_OVERRIDE;
			std::shared_ptr< setShootResponse_AsyncResult > send_setShootResponse(const ::SeaBattle::ShootRezult::type& rezult,
				const int16_t clientID);
			/**
			 * @param onSuccess The function which is executed if the request succeeds
			 * @param onError The function which is executed if the request fails
			 * @param userState Any object the user wants to store for the duration of the operation
			 * @param timeout Override of the timeout value specified in the IDL (negative to keep default)
			 */
			std::shared_ptr< setShootResponse_AsyncResult > send_setShootResponse(const ::SeaBattle::ShootRezult::type& rezult,
				const int16_t clientID,
				::thrift::TAsyncResult::SuccessCallback onSuccess,
				::thrift::TAsyncResult::ErrorCallback onError,
				void* userState = NULL,
				int32_t timeout = -1);
			/**
			 * Blocks until the result of a setShootResponse Call is received. Then the return value will be returned or exceptions will be thrown.
			 */
			void recv_setShootResponse(std::shared_ptr< setShootResponse_AsyncResult > & asyncResult);
		protected:
			/**
			 * Decode the response to a setShootResponse Call
			 */
			TM_DECL_LOCAL static void decode_setShootResponse(const std::shared_ptr< ::thrift::transport::TMessageBuffer >& message,
				const ::thrift::protocol::TMessageHeader& messageHeader,
				const std::shared_ptr< ::thrift::transport::TTransport >& iTrans,
				const std::shared_ptr< ::thrift::TAsyncResult >& asyncResult);

		public:
			typedef ::thrift::TSpecificAsyncResult< ::thrift::TAsyncResult::SuccessCallback, SeaBattleParameters::setShoot_result, void > setShoot_AsyncResult;
			typedef ::thrift::TCompletableSpecificAsyncResult< ::thrift::TAsyncResult::SuccessCallback, SeaBattleParameters::setShoot_result, void > setShoot_CompletableAsyncResult;
			virtual void setShoot(const int32_t x,
				const int32_t y,
				const int16_t clientID) TM_CXXLANG_OVERRIDE;
			std::shared_ptr< setShoot_AsyncResult > send_setShoot(const int32_t x,
				const int32_t y,
				const int16_t clientID);
			/**
			 * @param onSuccess The function which is executed if the request succeeds
			 * @param onError The function which is executed if the request fails
			 * @param userState Any object the user wants to store for the duration of the operation
			 * @param timeout Override of the timeout value specified in the IDL (negative to keep default)
			 */
			std::shared_ptr< setShoot_AsyncResult > send_setShoot(const int32_t x,
				const int32_t y,
				const int16_t clientID,
				::thrift::TAsyncResult::SuccessCallback onSuccess,
				::thrift::TAsyncResult::ErrorCallback onError,
				void* userState = NULL,
				int32_t timeout = -1);
			/**
			 * Blocks until the result of a setShoot Call is received. Then the return value will be returned or exceptions will be thrown.
			 */
			void recv_setShoot(std::shared_ptr< setShoot_AsyncResult > & asyncResult);
		protected:
			/**
			 * Decode the response to a setShoot Call
			 */
			TM_DECL_LOCAL static void decode_setShoot(const std::shared_ptr< ::thrift::transport::TMessageBuffer >& message,
				const ::thrift::protocol::TMessageHeader& messageHeader,
				const std::shared_ptr< ::thrift::transport::TTransport >& iTrans,
				const std::shared_ptr< ::thrift::TAsyncResult >& asyncResult);

		public:
			typedef ::thrift::TSpecificAsyncResult< ::thrift::TAsyncResult::SuccessCallback, SeaBattleParameters::subscribe_result, void > subscribe_AsyncResult;
			typedef ::thrift::TCompletableSpecificAsyncResult< ::thrift::TAsyncResult::SuccessCallback, SeaBattleParameters::subscribe_result, void > subscribe_CompletableAsyncResult;
			virtual void subscribe(const int16_t clientID) TM_CXXLANG_OVERRIDE;
			std::shared_ptr< subscribe_AsyncResult > send_subscribe(const int16_t clientID);
			/**
			 * @param onSuccess The function which is executed if the request succeeds
			 * @param onError The function which is executed if the request fails
			 * @param userState Any object the user wants to store for the duration of the operation
			 * @param timeout Override of the timeout value specified in the IDL (negative to keep default)
			 */
			std::shared_ptr< subscribe_AsyncResult > send_subscribe(const int16_t clientID,
				::thrift::TAsyncResult::SuccessCallback onSuccess,
				::thrift::TAsyncResult::ErrorCallback onError,
				void* userState = NULL,
				int32_t timeout = -1);
			/**
			 * Blocks until the result of a subscribe Call is received. Then the return value will be returned or exceptions will be thrown.
			 */
			void recv_subscribe(std::shared_ptr< subscribe_AsyncResult > & asyncResult);
		protected:
			/**
			 * Decode the response to a subscribe Call
			 */
			TM_DECL_LOCAL static void decode_subscribe(const std::shared_ptr< ::thrift::transport::TMessageBuffer >& message,
				const ::thrift::protocol::TMessageHeader& messageHeader,
				const std::shared_ptr< ::thrift::transport::TTransport >& iTrans,
				const std::shared_ptr< ::thrift::TAsyncResult >& asyncResult);

		public:
			typedef ::thrift::TSpecificAsyncResult< ::thrift::TAsyncResult::SuccessCallback, SeaBattleParameters::unsubscribe_result, void > unsubscribe_AsyncResult;
			typedef ::thrift::TCompletableSpecificAsyncResult< ::thrift::TAsyncResult::SuccessCallback, SeaBattleParameters::unsubscribe_result, void > unsubscribe_CompletableAsyncResult;
			virtual void unsubscribe(const int16_t clientID) TM_CXXLANG_OVERRIDE;
			std::shared_ptr< unsubscribe_AsyncResult > send_unsubscribe(const int16_t clientID);
			/**
			 * @param onSuccess The function which is executed if the request succeeds
			 * @param onError The function which is executed if the request fails
			 * @param userState Any object the user wants to store for the duration of the operation
			 * @param timeout Override of the timeout value specified in the IDL (negative to keep default)
			 */
			std::shared_ptr< unsubscribe_AsyncResult > send_unsubscribe(const int16_t clientID,
				::thrift::TAsyncResult::SuccessCallback onSuccess,
				::thrift::TAsyncResult::ErrorCallback onError,
				void* userState = NULL,
				int32_t timeout = -1);
			/**
			 * Blocks until the result of a unsubscribe Call is received. Then the return value will be returned or exceptions will be thrown.
			 */
			void recv_unsubscribe(std::shared_ptr< unsubscribe_AsyncResult > & asyncResult);
		protected:
			/**
			 * Decode the response to a unsubscribe Call
			 */
			TM_DECL_LOCAL static void decode_unsubscribe(const std::shared_ptr< ::thrift::transport::TMessageBuffer >& message,
				const ::thrift::protocol::TMessageHeader& messageHeader,
				const std::shared_ptr< ::thrift::transport::TTransport >& iTrans,
				const std::shared_ptr< ::thrift::TAsyncResult >& asyncResult);

		public:
	};

}

#if defined(_MSC_VER)
#pragma warning ( pop )
#endif

#endif // _SEABATTLE_SEABATTLE_

