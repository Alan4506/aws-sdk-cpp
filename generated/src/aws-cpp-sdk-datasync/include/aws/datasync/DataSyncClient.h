﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/datasync/DataSync_EXPORTS.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/client/AWSClient.h>
#include <aws/core/client/AWSClientAsyncCRTP.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/datasync/DataSyncServiceClientModel.h>

namespace Aws
{
namespace DataSync
{
  /**
   * <fullname>DataSync</fullname> <p>DataSync is an online data movement and
   * discovery service that simplifies data migration and helps you quickly, easily,
   * and securely transfer your file or object data to, from, and between Amazon Web
   * Services storage services.</p> <p>This API interface reference includes
   * documentation for using DataSync programmatically. For complete information, see
   * the <i> <a
   * href="https://docs.aws.amazon.com/datasync/latest/userguide/what-is-datasync.html">DataSync
   * User Guide</a> </i>.</p>
   */
  class AWS_DATASYNC_API DataSyncClient : public Aws::Client::AWSJsonClient, public Aws::Client::ClientWithAsyncTemplateMethods<DataSyncClient>
  {
    public:
      typedef Aws::Client::AWSJsonClient BASECLASS;
      static const char* GetServiceName();
      static const char* GetAllocationTag();

      typedef DataSyncClientConfiguration ClientConfigurationType;
      typedef DataSyncEndpointProvider EndpointProviderType;

       /**
        * Initializes client to use DefaultCredentialProviderChain, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        DataSyncClient(const Aws::DataSync::DataSyncClientConfiguration& clientConfiguration = Aws::DataSync::DataSyncClientConfiguration(),
                       std::shared_ptr<DataSyncEndpointProviderBase> endpointProvider = nullptr);

       /**
        * Initializes client to use SimpleAWSCredentialsProvider, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        DataSyncClient(const Aws::Auth::AWSCredentials& credentials,
                       std::shared_ptr<DataSyncEndpointProviderBase> endpointProvider = nullptr,
                       const Aws::DataSync::DataSyncClientConfiguration& clientConfiguration = Aws::DataSync::DataSyncClientConfiguration());

       /**
        * Initializes client to use specified credentials provider with specified client config. If http client factory is not supplied,
        * the default http client factory will be used
        */
        DataSyncClient(const std::shared_ptr<Aws::Auth::AWSCredentialsProvider>& credentialsProvider,
                       std::shared_ptr<DataSyncEndpointProviderBase> endpointProvider = nullptr,
                       const Aws::DataSync::DataSyncClientConfiguration& clientConfiguration = Aws::DataSync::DataSyncClientConfiguration());


        /* Legacy constructors due deprecation */
       /**
        * Initializes client to use DefaultCredentialProviderChain, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        DataSyncClient(const Aws::Client::ClientConfiguration& clientConfiguration);

       /**
        * Initializes client to use SimpleAWSCredentialsProvider, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        DataSyncClient(const Aws::Auth::AWSCredentials& credentials,
                       const Aws::Client::ClientConfiguration& clientConfiguration);

       /**
        * Initializes client to use specified credentials provider with specified client config. If http client factory is not supplied,
        * the default http client factory will be used
        */
        DataSyncClient(const std::shared_ptr<Aws::Auth::AWSCredentialsProvider>& credentialsProvider,
                       const Aws::Client::ClientConfiguration& clientConfiguration);

        /* End of legacy constructors due deprecation */
        virtual ~DataSyncClient();

        /**
         * <p>Stops an DataSync task execution that's in progress. The transfer of some
         * files are abruptly interrupted. File contents that're transferred to the
         * destination might be incomplete or inconsistent with the source files.</p>
         * <p>However, if you start a new task execution using the same task and allow it
         * to finish, file content on the destination will be complete and consistent. This
         * applies to other unexpected failures that interrupt a task execution. In all of
         * these cases, DataSync successfully completes the transfer when you start the
         * next task execution.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CancelTaskExecution">AWS
         * API Reference</a></p>
         */
        virtual Model::CancelTaskExecutionOutcome CancelTaskExecution(const Model::CancelTaskExecutionRequest& request) const;

        /**
         * A Callable wrapper for CancelTaskExecution that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CancelTaskExecutionRequestT = Model::CancelTaskExecutionRequest>
        Model::CancelTaskExecutionOutcomeCallable CancelTaskExecutionCallable(const CancelTaskExecutionRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CancelTaskExecution, request);
        }

        /**
         * An Async wrapper for CancelTaskExecution that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CancelTaskExecutionRequestT = Model::CancelTaskExecutionRequest>
        void CancelTaskExecutionAsync(const CancelTaskExecutionRequestT& request, const CancelTaskExecutionResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CancelTaskExecution, request, handler, context);
        }

        /**
         * <p>Activates an DataSync agent that you deploy in your storage environment. The
         * activation process associates the agent with your Amazon Web Services
         * account.</p> <p>If you haven't deployed an agent yet, see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/do-i-need-datasync-agent.html">Do
         * I need a DataSync agent?</a> </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CreateAgent">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateAgentOutcome CreateAgent(const Model::CreateAgentRequest& request) const;

        /**
         * A Callable wrapper for CreateAgent that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateAgentRequestT = Model::CreateAgentRequest>
        Model::CreateAgentOutcomeCallable CreateAgentCallable(const CreateAgentRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CreateAgent, request);
        }

        /**
         * An Async wrapper for CreateAgent that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateAgentRequestT = Model::CreateAgentRequest>
        void CreateAgentAsync(const CreateAgentRequestT& request, const CreateAgentResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CreateAgent, request, handler, context);
        }

        /**
         * <p>Creates a transfer <i>location</i> for a Microsoft Azure Blob Storage
         * container. DataSync can use this location as a transfer source or
         * destination.</p> <p>Before you begin, make sure you know <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/creating-azure-blob-location.html#azure-blob-access">how
         * DataSync accesses Azure Blob Storage</a> and works with <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/creating-azure-blob-location.html#azure-blob-access-tiers">access
         * tiers</a> and <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/creating-azure-blob-location.html#blob-types">blob
         * types</a>. You also need a <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/creating-azure-blob-location.html#azure-blob-creating-agent">DataSync
         * agent</a> that can connect to your container.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CreateLocationAzureBlob">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateLocationAzureBlobOutcome CreateLocationAzureBlob(const Model::CreateLocationAzureBlobRequest& request) const;

        /**
         * A Callable wrapper for CreateLocationAzureBlob that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateLocationAzureBlobRequestT = Model::CreateLocationAzureBlobRequest>
        Model::CreateLocationAzureBlobOutcomeCallable CreateLocationAzureBlobCallable(const CreateLocationAzureBlobRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CreateLocationAzureBlob, request);
        }

        /**
         * An Async wrapper for CreateLocationAzureBlob that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateLocationAzureBlobRequestT = Model::CreateLocationAzureBlobRequest>
        void CreateLocationAzureBlobAsync(const CreateLocationAzureBlobRequestT& request, const CreateLocationAzureBlobResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CreateLocationAzureBlob, request, handler, context);
        }

        /**
         * <p>Creates a transfer <i>location</i> for an Amazon EFS file system. DataSync
         * can use this location as a source or destination for transferring data.</p>
         * <p>Before you begin, make sure that you understand how DataSync <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-efs-location.html#create-efs-location-access">accesses
         * Amazon EFS file systems</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CreateLocationEfs">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateLocationEfsOutcome CreateLocationEfs(const Model::CreateLocationEfsRequest& request) const;

        /**
         * A Callable wrapper for CreateLocationEfs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateLocationEfsRequestT = Model::CreateLocationEfsRequest>
        Model::CreateLocationEfsOutcomeCallable CreateLocationEfsCallable(const CreateLocationEfsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CreateLocationEfs, request);
        }

        /**
         * An Async wrapper for CreateLocationEfs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateLocationEfsRequestT = Model::CreateLocationEfsRequest>
        void CreateLocationEfsAsync(const CreateLocationEfsRequestT& request, const CreateLocationEfsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CreateLocationEfs, request, handler, context);
        }

        /**
         * <p>Creates a transfer <i>location</i> for an Amazon FSx for Lustre file system.
         * DataSync can use this location as a source or destination for transferring
         * data.</p> <p>Before you begin, make sure that you understand how DataSync <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-lustre-location.html#create-lustre-location-access">accesses
         * FSx for Lustre file systems</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CreateLocationFsxLustre">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateLocationFsxLustreOutcome CreateLocationFsxLustre(const Model::CreateLocationFsxLustreRequest& request) const;

        /**
         * A Callable wrapper for CreateLocationFsxLustre that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateLocationFsxLustreRequestT = Model::CreateLocationFsxLustreRequest>
        Model::CreateLocationFsxLustreOutcomeCallable CreateLocationFsxLustreCallable(const CreateLocationFsxLustreRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CreateLocationFsxLustre, request);
        }

        /**
         * An Async wrapper for CreateLocationFsxLustre that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateLocationFsxLustreRequestT = Model::CreateLocationFsxLustreRequest>
        void CreateLocationFsxLustreAsync(const CreateLocationFsxLustreRequestT& request, const CreateLocationFsxLustreResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CreateLocationFsxLustre, request, handler, context);
        }

        /**
         * <p>Creates a transfer <i>location</i> for an Amazon FSx for NetApp ONTAP file
         * system. DataSync can use this location as a source or destination for
         * transferring data.</p> <p>Before you begin, make sure that you understand how
         * DataSync <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-ontap-location.html#create-ontap-location-access">accesses
         * FSx for ONTAP file systems</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CreateLocationFsxOntap">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateLocationFsxOntapOutcome CreateLocationFsxOntap(const Model::CreateLocationFsxOntapRequest& request) const;

        /**
         * A Callable wrapper for CreateLocationFsxOntap that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateLocationFsxOntapRequestT = Model::CreateLocationFsxOntapRequest>
        Model::CreateLocationFsxOntapOutcomeCallable CreateLocationFsxOntapCallable(const CreateLocationFsxOntapRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CreateLocationFsxOntap, request);
        }

        /**
         * An Async wrapper for CreateLocationFsxOntap that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateLocationFsxOntapRequestT = Model::CreateLocationFsxOntapRequest>
        void CreateLocationFsxOntapAsync(const CreateLocationFsxOntapRequestT& request, const CreateLocationFsxOntapResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CreateLocationFsxOntap, request, handler, context);
        }

        /**
         * <p>Creates a transfer <i>location</i> for an Amazon FSx for OpenZFS file system.
         * DataSync can use this location as a source or destination for transferring
         * data.</p> <p>Before you begin, make sure that you understand how DataSync <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-openzfs-location.html#create-openzfs-access">accesses
         * FSx for OpenZFS file systems</a>.</p>  <p>Request parameters related to
         * <code>SMB</code> aren't supported with the <code>CreateLocationFsxOpenZfs</code>
         * operation.</p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CreateLocationFsxOpenZfs">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateLocationFsxOpenZfsOutcome CreateLocationFsxOpenZfs(const Model::CreateLocationFsxOpenZfsRequest& request) const;

        /**
         * A Callable wrapper for CreateLocationFsxOpenZfs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateLocationFsxOpenZfsRequestT = Model::CreateLocationFsxOpenZfsRequest>
        Model::CreateLocationFsxOpenZfsOutcomeCallable CreateLocationFsxOpenZfsCallable(const CreateLocationFsxOpenZfsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CreateLocationFsxOpenZfs, request);
        }

        /**
         * An Async wrapper for CreateLocationFsxOpenZfs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateLocationFsxOpenZfsRequestT = Model::CreateLocationFsxOpenZfsRequest>
        void CreateLocationFsxOpenZfsAsync(const CreateLocationFsxOpenZfsRequestT& request, const CreateLocationFsxOpenZfsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CreateLocationFsxOpenZfs, request, handler, context);
        }

        /**
         * <p>Creates a transfer <i>location</i> for an Amazon FSx for Windows File Server
         * file system. DataSync can use this location as a source or destination for
         * transferring data.</p> <p>Before you begin, make sure that you understand how
         * DataSync <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-fsx-location.html#create-fsx-location-access">accesses
         * FSx for Windows File Server file systems</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CreateLocationFsxWindows">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateLocationFsxWindowsOutcome CreateLocationFsxWindows(const Model::CreateLocationFsxWindowsRequest& request) const;

        /**
         * A Callable wrapper for CreateLocationFsxWindows that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateLocationFsxWindowsRequestT = Model::CreateLocationFsxWindowsRequest>
        Model::CreateLocationFsxWindowsOutcomeCallable CreateLocationFsxWindowsCallable(const CreateLocationFsxWindowsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CreateLocationFsxWindows, request);
        }

        /**
         * An Async wrapper for CreateLocationFsxWindows that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateLocationFsxWindowsRequestT = Model::CreateLocationFsxWindowsRequest>
        void CreateLocationFsxWindowsAsync(const CreateLocationFsxWindowsRequestT& request, const CreateLocationFsxWindowsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CreateLocationFsxWindows, request, handler, context);
        }

        /**
         * <p>Creates a transfer <i>location</i> for a Hadoop Distributed File System
         * (HDFS). DataSync can use this location as a source or destination for
         * transferring data.</p> <p>Before you begin, make sure that you understand how
         * DataSync <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-hdfs-location.html#accessing-hdfs">accesses
         * HDFS clusters</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CreateLocationHdfs">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateLocationHdfsOutcome CreateLocationHdfs(const Model::CreateLocationHdfsRequest& request) const;

        /**
         * A Callable wrapper for CreateLocationHdfs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateLocationHdfsRequestT = Model::CreateLocationHdfsRequest>
        Model::CreateLocationHdfsOutcomeCallable CreateLocationHdfsCallable(const CreateLocationHdfsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CreateLocationHdfs, request);
        }

        /**
         * An Async wrapper for CreateLocationHdfs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateLocationHdfsRequestT = Model::CreateLocationHdfsRequest>
        void CreateLocationHdfsAsync(const CreateLocationHdfsRequestT& request, const CreateLocationHdfsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CreateLocationHdfs, request, handler, context);
        }

        /**
         * <p>Creates a transfer <i>location</i> for a Network File System (NFS) file
         * server. DataSync can use this location as a source or destination for
         * transferring data.</p> <p>Before you begin, make sure that you understand how
         * DataSync <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-nfs-location.html#accessing-nfs">accesses
         * NFS file servers</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CreateLocationNfs">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateLocationNfsOutcome CreateLocationNfs(const Model::CreateLocationNfsRequest& request) const;

        /**
         * A Callable wrapper for CreateLocationNfs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateLocationNfsRequestT = Model::CreateLocationNfsRequest>
        Model::CreateLocationNfsOutcomeCallable CreateLocationNfsCallable(const CreateLocationNfsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CreateLocationNfs, request);
        }

        /**
         * An Async wrapper for CreateLocationNfs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateLocationNfsRequestT = Model::CreateLocationNfsRequest>
        void CreateLocationNfsAsync(const CreateLocationNfsRequestT& request, const CreateLocationNfsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CreateLocationNfs, request, handler, context);
        }

        /**
         * <p>Creates a transfer <i>location</i> for an object storage system. DataSync can
         * use this location as a source or destination for transferring data.</p>
         * <p>Before you begin, make sure that you understand the <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-object-location.html#create-object-location-prerequisites">prerequisites</a>
         * for DataSync to work with object storage systems.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CreateLocationObjectStorage">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateLocationObjectStorageOutcome CreateLocationObjectStorage(const Model::CreateLocationObjectStorageRequest& request) const;

        /**
         * A Callable wrapper for CreateLocationObjectStorage that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateLocationObjectStorageRequestT = Model::CreateLocationObjectStorageRequest>
        Model::CreateLocationObjectStorageOutcomeCallable CreateLocationObjectStorageCallable(const CreateLocationObjectStorageRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CreateLocationObjectStorage, request);
        }

        /**
         * An Async wrapper for CreateLocationObjectStorage that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateLocationObjectStorageRequestT = Model::CreateLocationObjectStorageRequest>
        void CreateLocationObjectStorageAsync(const CreateLocationObjectStorageRequestT& request, const CreateLocationObjectStorageResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CreateLocationObjectStorage, request, handler, context);
        }

        /**
         * <p>Creates a transfer <i>location</i> for an Amazon S3 bucket. DataSync can use
         * this location as a source or destination for transferring data.</p> 
         * <p>Before you begin, make sure that you read the following topics:</p> <ul> <li>
         * <p> <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-s3-location.html#using-storage-classes">Storage
         * class considerations with Amazon S3 locations</a> </p> </li> <li> <p> <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-s3-location.html#create-s3-location-s3-requests">Evaluating
         * S3 request costs when using DataSync</a> </p> </li> </ul>  <p> For
         * more information, see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-s3-location.html">Configuring
         * transfers with Amazon S3</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CreateLocationS3">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateLocationS3Outcome CreateLocationS3(const Model::CreateLocationS3Request& request) const;

        /**
         * A Callable wrapper for CreateLocationS3 that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateLocationS3RequestT = Model::CreateLocationS3Request>
        Model::CreateLocationS3OutcomeCallable CreateLocationS3Callable(const CreateLocationS3RequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CreateLocationS3, request);
        }

        /**
         * An Async wrapper for CreateLocationS3 that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateLocationS3RequestT = Model::CreateLocationS3Request>
        void CreateLocationS3Async(const CreateLocationS3RequestT& request, const CreateLocationS3ResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CreateLocationS3, request, handler, context);
        }

        /**
         * <p>Creates a transfer <i>location</i> for a Server Message Block (SMB) file
         * server. DataSync can use this location as a source or destination for
         * transferring data.</p> <p>Before you begin, make sure that you understand how
         * DataSync accesses SMB file servers. For more information, see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-smb-location.html#configuring-smb-permissions">Providing
         * DataSync access to SMB file servers</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CreateLocationSmb">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateLocationSmbOutcome CreateLocationSmb(const Model::CreateLocationSmbRequest& request) const;

        /**
         * A Callable wrapper for CreateLocationSmb that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateLocationSmbRequestT = Model::CreateLocationSmbRequest>
        Model::CreateLocationSmbOutcomeCallable CreateLocationSmbCallable(const CreateLocationSmbRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CreateLocationSmb, request);
        }

        /**
         * An Async wrapper for CreateLocationSmb that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateLocationSmbRequestT = Model::CreateLocationSmbRequest>
        void CreateLocationSmbAsync(const CreateLocationSmbRequestT& request, const CreateLocationSmbResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CreateLocationSmb, request, handler, context);
        }

        /**
         * <p>Configures a <i>task</i>, which defines where and how DataSync transfers your
         * data.</p> <p>A task includes a source location, destination location, and
         * transfer options (such as bandwidth limits, scheduling, and more).</p>
         *  <p>If you're planning to transfer data to or from an Amazon S3
         * location, review <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-s3-location.html#create-s3-location-s3-requests">how
         * DataSync can affect your S3 request charges</a> and the <a
         * href="http://aws.amazon.com/datasync/pricing/">DataSync pricing page</a> before
         * you begin.</p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/CreateTask">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateTaskOutcome CreateTask(const Model::CreateTaskRequest& request) const;

        /**
         * A Callable wrapper for CreateTask that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename CreateTaskRequestT = Model::CreateTaskRequest>
        Model::CreateTaskOutcomeCallable CreateTaskCallable(const CreateTaskRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::CreateTask, request);
        }

        /**
         * An Async wrapper for CreateTask that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename CreateTaskRequestT = Model::CreateTaskRequest>
        void CreateTaskAsync(const CreateTaskRequestT& request, const CreateTaskResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::CreateTask, request, handler, context);
        }

        /**
         * <p>Removes an DataSync agent resource from your Amazon Web Services account.</p>
         * <p>Keep in mind that this operation (which can't be undone) doesn't remove the
         * agent's virtual machine (VM) or Amazon EC2 instance from your storage
         * environment. For next steps, you can delete the VM or instance from your storage
         * environment or reuse it to <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/activate-agent.html">activate
         * a new agent</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DeleteAgent">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteAgentOutcome DeleteAgent(const Model::DeleteAgentRequest& request) const;

        /**
         * A Callable wrapper for DeleteAgent that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DeleteAgentRequestT = Model::DeleteAgentRequest>
        Model::DeleteAgentOutcomeCallable DeleteAgentCallable(const DeleteAgentRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DeleteAgent, request);
        }

        /**
         * An Async wrapper for DeleteAgent that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DeleteAgentRequestT = Model::DeleteAgentRequest>
        void DeleteAgentAsync(const DeleteAgentRequestT& request, const DeleteAgentResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DeleteAgent, request, handler, context);
        }

        /**
         * <p>Deletes a transfer location resource from DataSync. </p><p><h3>See Also:</h3>
         * <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DeleteLocation">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteLocationOutcome DeleteLocation(const Model::DeleteLocationRequest& request) const;

        /**
         * A Callable wrapper for DeleteLocation that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DeleteLocationRequestT = Model::DeleteLocationRequest>
        Model::DeleteLocationOutcomeCallable DeleteLocationCallable(const DeleteLocationRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DeleteLocation, request);
        }

        /**
         * An Async wrapper for DeleteLocation that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DeleteLocationRequestT = Model::DeleteLocationRequest>
        void DeleteLocationAsync(const DeleteLocationRequestT& request, const DeleteLocationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DeleteLocation, request, handler, context);
        }

        /**
         * <p>Deletes a transfer task resource from DataSync.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DeleteTask">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteTaskOutcome DeleteTask(const Model::DeleteTaskRequest& request) const;

        /**
         * A Callable wrapper for DeleteTask that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DeleteTaskRequestT = Model::DeleteTaskRequest>
        Model::DeleteTaskOutcomeCallable DeleteTaskCallable(const DeleteTaskRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DeleteTask, request);
        }

        /**
         * An Async wrapper for DeleteTask that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DeleteTaskRequestT = Model::DeleteTaskRequest>
        void DeleteTaskAsync(const DeleteTaskRequestT& request, const DeleteTaskResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DeleteTask, request, handler, context);
        }

        /**
         * <p>Returns information about an DataSync agent, such as its name, service
         * endpoint type, and status.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeAgent">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeAgentOutcome DescribeAgent(const Model::DescribeAgentRequest& request) const;

        /**
         * A Callable wrapper for DescribeAgent that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeAgentRequestT = Model::DescribeAgentRequest>
        Model::DescribeAgentOutcomeCallable DescribeAgentCallable(const DescribeAgentRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeAgent, request);
        }

        /**
         * An Async wrapper for DescribeAgent that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeAgentRequestT = Model::DescribeAgentRequest>
        void DescribeAgentAsync(const DescribeAgentRequestT& request, const DescribeAgentResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeAgent, request, handler, context);
        }

        /**
         * <p>Provides details about how an DataSync transfer location for Microsoft Azure
         * Blob Storage is configured.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeLocationAzureBlob">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeLocationAzureBlobOutcome DescribeLocationAzureBlob(const Model::DescribeLocationAzureBlobRequest& request) const;

        /**
         * A Callable wrapper for DescribeLocationAzureBlob that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeLocationAzureBlobRequestT = Model::DescribeLocationAzureBlobRequest>
        Model::DescribeLocationAzureBlobOutcomeCallable DescribeLocationAzureBlobCallable(const DescribeLocationAzureBlobRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeLocationAzureBlob, request);
        }

        /**
         * An Async wrapper for DescribeLocationAzureBlob that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeLocationAzureBlobRequestT = Model::DescribeLocationAzureBlobRequest>
        void DescribeLocationAzureBlobAsync(const DescribeLocationAzureBlobRequestT& request, const DescribeLocationAzureBlobResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeLocationAzureBlob, request, handler, context);
        }

        /**
         * <p>Provides details about how an DataSync transfer location for an Amazon EFS
         * file system is configured.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeLocationEfs">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeLocationEfsOutcome DescribeLocationEfs(const Model::DescribeLocationEfsRequest& request) const;

        /**
         * A Callable wrapper for DescribeLocationEfs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeLocationEfsRequestT = Model::DescribeLocationEfsRequest>
        Model::DescribeLocationEfsOutcomeCallable DescribeLocationEfsCallable(const DescribeLocationEfsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeLocationEfs, request);
        }

        /**
         * An Async wrapper for DescribeLocationEfs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeLocationEfsRequestT = Model::DescribeLocationEfsRequest>
        void DescribeLocationEfsAsync(const DescribeLocationEfsRequestT& request, const DescribeLocationEfsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeLocationEfs, request, handler, context);
        }

        /**
         * <p>Provides details about how an DataSync transfer location for an Amazon FSx
         * for Lustre file system is configured.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeLocationFsxLustre">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeLocationFsxLustreOutcome DescribeLocationFsxLustre(const Model::DescribeLocationFsxLustreRequest& request) const;

        /**
         * A Callable wrapper for DescribeLocationFsxLustre that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeLocationFsxLustreRequestT = Model::DescribeLocationFsxLustreRequest>
        Model::DescribeLocationFsxLustreOutcomeCallable DescribeLocationFsxLustreCallable(const DescribeLocationFsxLustreRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeLocationFsxLustre, request);
        }

        /**
         * An Async wrapper for DescribeLocationFsxLustre that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeLocationFsxLustreRequestT = Model::DescribeLocationFsxLustreRequest>
        void DescribeLocationFsxLustreAsync(const DescribeLocationFsxLustreRequestT& request, const DescribeLocationFsxLustreResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeLocationFsxLustre, request, handler, context);
        }

        /**
         * <p>Provides details about how an DataSync transfer location for an Amazon FSx
         * for NetApp ONTAP file system is configured.</p>  <p>If your location uses
         * SMB, the <code>DescribeLocationFsxOntap</code> operation doesn't actually return
         * a <code>Password</code>.</p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeLocationFsxOntap">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeLocationFsxOntapOutcome DescribeLocationFsxOntap(const Model::DescribeLocationFsxOntapRequest& request) const;

        /**
         * A Callable wrapper for DescribeLocationFsxOntap that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeLocationFsxOntapRequestT = Model::DescribeLocationFsxOntapRequest>
        Model::DescribeLocationFsxOntapOutcomeCallable DescribeLocationFsxOntapCallable(const DescribeLocationFsxOntapRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeLocationFsxOntap, request);
        }

        /**
         * An Async wrapper for DescribeLocationFsxOntap that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeLocationFsxOntapRequestT = Model::DescribeLocationFsxOntapRequest>
        void DescribeLocationFsxOntapAsync(const DescribeLocationFsxOntapRequestT& request, const DescribeLocationFsxOntapResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeLocationFsxOntap, request, handler, context);
        }

        /**
         * <p>Provides details about how an DataSync transfer location for an Amazon FSx
         * for OpenZFS file system is configured.</p>  <p>Response elements related
         * to <code>SMB</code> aren't supported with the
         * <code>DescribeLocationFsxOpenZfs</code> operation.</p> <p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeLocationFsxOpenZfs">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeLocationFsxOpenZfsOutcome DescribeLocationFsxOpenZfs(const Model::DescribeLocationFsxOpenZfsRequest& request) const;

        /**
         * A Callable wrapper for DescribeLocationFsxOpenZfs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeLocationFsxOpenZfsRequestT = Model::DescribeLocationFsxOpenZfsRequest>
        Model::DescribeLocationFsxOpenZfsOutcomeCallable DescribeLocationFsxOpenZfsCallable(const DescribeLocationFsxOpenZfsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeLocationFsxOpenZfs, request);
        }

        /**
         * An Async wrapper for DescribeLocationFsxOpenZfs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeLocationFsxOpenZfsRequestT = Model::DescribeLocationFsxOpenZfsRequest>
        void DescribeLocationFsxOpenZfsAsync(const DescribeLocationFsxOpenZfsRequestT& request, const DescribeLocationFsxOpenZfsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeLocationFsxOpenZfs, request, handler, context);
        }

        /**
         * <p>Provides details about how an DataSync transfer location for an Amazon FSx
         * for Windows File Server file system is configured.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeLocationFsxWindows">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeLocationFsxWindowsOutcome DescribeLocationFsxWindows(const Model::DescribeLocationFsxWindowsRequest& request) const;

        /**
         * A Callable wrapper for DescribeLocationFsxWindows that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeLocationFsxWindowsRequestT = Model::DescribeLocationFsxWindowsRequest>
        Model::DescribeLocationFsxWindowsOutcomeCallable DescribeLocationFsxWindowsCallable(const DescribeLocationFsxWindowsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeLocationFsxWindows, request);
        }

        /**
         * An Async wrapper for DescribeLocationFsxWindows that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeLocationFsxWindowsRequestT = Model::DescribeLocationFsxWindowsRequest>
        void DescribeLocationFsxWindowsAsync(const DescribeLocationFsxWindowsRequestT& request, const DescribeLocationFsxWindowsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeLocationFsxWindows, request, handler, context);
        }

        /**
         * <p>Provides details about how an DataSync transfer location for a Hadoop
         * Distributed File System (HDFS) is configured.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeLocationHdfs">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeLocationHdfsOutcome DescribeLocationHdfs(const Model::DescribeLocationHdfsRequest& request) const;

        /**
         * A Callable wrapper for DescribeLocationHdfs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeLocationHdfsRequestT = Model::DescribeLocationHdfsRequest>
        Model::DescribeLocationHdfsOutcomeCallable DescribeLocationHdfsCallable(const DescribeLocationHdfsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeLocationHdfs, request);
        }

        /**
         * An Async wrapper for DescribeLocationHdfs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeLocationHdfsRequestT = Model::DescribeLocationHdfsRequest>
        void DescribeLocationHdfsAsync(const DescribeLocationHdfsRequestT& request, const DescribeLocationHdfsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeLocationHdfs, request, handler, context);
        }

        /**
         * <p>Provides details about how an DataSync transfer location for a Network File
         * System (NFS) file server is configured.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeLocationNfs">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeLocationNfsOutcome DescribeLocationNfs(const Model::DescribeLocationNfsRequest& request) const;

        /**
         * A Callable wrapper for DescribeLocationNfs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeLocationNfsRequestT = Model::DescribeLocationNfsRequest>
        Model::DescribeLocationNfsOutcomeCallable DescribeLocationNfsCallable(const DescribeLocationNfsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeLocationNfs, request);
        }

        /**
         * An Async wrapper for DescribeLocationNfs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeLocationNfsRequestT = Model::DescribeLocationNfsRequest>
        void DescribeLocationNfsAsync(const DescribeLocationNfsRequestT& request, const DescribeLocationNfsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeLocationNfs, request, handler, context);
        }

        /**
         * <p>Provides details about how an DataSync transfer location for an object
         * storage system is configured.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeLocationObjectStorage">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeLocationObjectStorageOutcome DescribeLocationObjectStorage(const Model::DescribeLocationObjectStorageRequest& request) const;

        /**
         * A Callable wrapper for DescribeLocationObjectStorage that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeLocationObjectStorageRequestT = Model::DescribeLocationObjectStorageRequest>
        Model::DescribeLocationObjectStorageOutcomeCallable DescribeLocationObjectStorageCallable(const DescribeLocationObjectStorageRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeLocationObjectStorage, request);
        }

        /**
         * An Async wrapper for DescribeLocationObjectStorage that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeLocationObjectStorageRequestT = Model::DescribeLocationObjectStorageRequest>
        void DescribeLocationObjectStorageAsync(const DescribeLocationObjectStorageRequestT& request, const DescribeLocationObjectStorageResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeLocationObjectStorage, request, handler, context);
        }

        /**
         * <p>Provides details about how an DataSync transfer location for an S3 bucket is
         * configured.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeLocationS3">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeLocationS3Outcome DescribeLocationS3(const Model::DescribeLocationS3Request& request) const;

        /**
         * A Callable wrapper for DescribeLocationS3 that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeLocationS3RequestT = Model::DescribeLocationS3Request>
        Model::DescribeLocationS3OutcomeCallable DescribeLocationS3Callable(const DescribeLocationS3RequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeLocationS3, request);
        }

        /**
         * An Async wrapper for DescribeLocationS3 that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeLocationS3RequestT = Model::DescribeLocationS3Request>
        void DescribeLocationS3Async(const DescribeLocationS3RequestT& request, const DescribeLocationS3ResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeLocationS3, request, handler, context);
        }

        /**
         * <p>Provides details about how an DataSync transfer location for a Server Message
         * Block (SMB) file server is configured.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeLocationSmb">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeLocationSmbOutcome DescribeLocationSmb(const Model::DescribeLocationSmbRequest& request) const;

        /**
         * A Callable wrapper for DescribeLocationSmb that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeLocationSmbRequestT = Model::DescribeLocationSmbRequest>
        Model::DescribeLocationSmbOutcomeCallable DescribeLocationSmbCallable(const DescribeLocationSmbRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeLocationSmb, request);
        }

        /**
         * An Async wrapper for DescribeLocationSmb that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeLocationSmbRequestT = Model::DescribeLocationSmbRequest>
        void DescribeLocationSmbAsync(const DescribeLocationSmbRequestT& request, const DescribeLocationSmbResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeLocationSmb, request, handler, context);
        }

        /**
         * <p>Provides information about a <i>task</i>, which defines where and how
         * DataSync transfers your data.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeTask">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeTaskOutcome DescribeTask(const Model::DescribeTaskRequest& request) const;

        /**
         * A Callable wrapper for DescribeTask that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeTaskRequestT = Model::DescribeTaskRequest>
        Model::DescribeTaskOutcomeCallable DescribeTaskCallable(const DescribeTaskRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeTask, request);
        }

        /**
         * An Async wrapper for DescribeTask that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeTaskRequestT = Model::DescribeTaskRequest>
        void DescribeTaskAsync(const DescribeTaskRequestT& request, const DescribeTaskResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeTask, request, handler, context);
        }

        /**
         * <p>Provides information about an execution of your DataSync task. You can use
         * this operation to help monitor the progress of an ongoing data transfer or check
         * the results of the transfer.</p>  <p>Some
         * <code>DescribeTaskExecution</code> response elements are only relevant to a
         * specific task mode. For information, see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/choosing-task-mode.html#task-mode-differences">Understanding
         * task mode differences</a> and <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/transfer-performance-counters.html">Understanding
         * data transfer performance counters</a>.</p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/DescribeTaskExecution">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeTaskExecutionOutcome DescribeTaskExecution(const Model::DescribeTaskExecutionRequest& request) const;

        /**
         * A Callable wrapper for DescribeTaskExecution that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename DescribeTaskExecutionRequestT = Model::DescribeTaskExecutionRequest>
        Model::DescribeTaskExecutionOutcomeCallable DescribeTaskExecutionCallable(const DescribeTaskExecutionRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::DescribeTaskExecution, request);
        }

        /**
         * An Async wrapper for DescribeTaskExecution that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename DescribeTaskExecutionRequestT = Model::DescribeTaskExecutionRequest>
        void DescribeTaskExecutionAsync(const DescribeTaskExecutionRequestT& request, const DescribeTaskExecutionResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::DescribeTaskExecution, request, handler, context);
        }

        /**
         * <p>Returns a list of DataSync agents that belong to an Amazon Web Services
         * account in the Amazon Web Services Region specified in the request.</p> <p>With
         * pagination, you can reduce the number of agents returned in a response. If you
         * get a truncated list of agents in a response, the response contains a marker
         * that you can specify in your next request to fetch the next page of agents.</p>
         * <p> <code>ListAgents</code> is eventually consistent. This means the result of
         * running the operation might not reflect that you just created or deleted an
         * agent. For example, if you create an agent with <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/API_CreateAgent.html">CreateAgent</a>
         * and then immediately run <code>ListAgents</code>, that agent might not show up
         * in the list right away. In situations like this, you can always confirm whether
         * an agent has been created (or deleted) by using <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/API_DescribeAgent.html">DescribeAgent</a>.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/ListAgents">AWS
         * API Reference</a></p>
         */
        virtual Model::ListAgentsOutcome ListAgents(const Model::ListAgentsRequest& request = {}) const;

        /**
         * A Callable wrapper for ListAgents that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename ListAgentsRequestT = Model::ListAgentsRequest>
        Model::ListAgentsOutcomeCallable ListAgentsCallable(const ListAgentsRequestT& request = {}) const
        {
            return SubmitCallable(&DataSyncClient::ListAgents, request);
        }

        /**
         * An Async wrapper for ListAgents that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename ListAgentsRequestT = Model::ListAgentsRequest>
        void ListAgentsAsync(const ListAgentsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr, const ListAgentsRequestT& request = {}) const
        {
            return SubmitAsync(&DataSyncClient::ListAgents, request, handler, context);
        }

        /**
         * <p>Returns a list of source and destination locations.</p> <p>If you have more
         * locations than are returned in a response (that is, the response returns only a
         * truncated list of your agents), the response contains a token that you can
         * specify in your next request to fetch the next page of locations.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/ListLocations">AWS
         * API Reference</a></p>
         */
        virtual Model::ListLocationsOutcome ListLocations(const Model::ListLocationsRequest& request = {}) const;

        /**
         * A Callable wrapper for ListLocations that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename ListLocationsRequestT = Model::ListLocationsRequest>
        Model::ListLocationsOutcomeCallable ListLocationsCallable(const ListLocationsRequestT& request = {}) const
        {
            return SubmitCallable(&DataSyncClient::ListLocations, request);
        }

        /**
         * An Async wrapper for ListLocations that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename ListLocationsRequestT = Model::ListLocationsRequest>
        void ListLocationsAsync(const ListLocationsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr, const ListLocationsRequestT& request = {}) const
        {
            return SubmitAsync(&DataSyncClient::ListLocations, request, handler, context);
        }

        /**
         * <p>Returns all the tags associated with an Amazon Web Services
         * resource.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/ListTagsForResource">AWS
         * API Reference</a></p>
         */
        virtual Model::ListTagsForResourceOutcome ListTagsForResource(const Model::ListTagsForResourceRequest& request) const;

        /**
         * A Callable wrapper for ListTagsForResource that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename ListTagsForResourceRequestT = Model::ListTagsForResourceRequest>
        Model::ListTagsForResourceOutcomeCallable ListTagsForResourceCallable(const ListTagsForResourceRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::ListTagsForResource, request);
        }

        /**
         * An Async wrapper for ListTagsForResource that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename ListTagsForResourceRequestT = Model::ListTagsForResourceRequest>
        void ListTagsForResourceAsync(const ListTagsForResourceRequestT& request, const ListTagsForResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::ListTagsForResource, request, handler, context);
        }

        /**
         * <p>Returns a list of executions for an DataSync transfer task.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/ListTaskExecutions">AWS
         * API Reference</a></p>
         */
        virtual Model::ListTaskExecutionsOutcome ListTaskExecutions(const Model::ListTaskExecutionsRequest& request = {}) const;

        /**
         * A Callable wrapper for ListTaskExecutions that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename ListTaskExecutionsRequestT = Model::ListTaskExecutionsRequest>
        Model::ListTaskExecutionsOutcomeCallable ListTaskExecutionsCallable(const ListTaskExecutionsRequestT& request = {}) const
        {
            return SubmitCallable(&DataSyncClient::ListTaskExecutions, request);
        }

        /**
         * An Async wrapper for ListTaskExecutions that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename ListTaskExecutionsRequestT = Model::ListTaskExecutionsRequest>
        void ListTaskExecutionsAsync(const ListTaskExecutionsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr, const ListTaskExecutionsRequestT& request = {}) const
        {
            return SubmitAsync(&DataSyncClient::ListTaskExecutions, request, handler, context);
        }

        /**
         * <p>Returns a list of the DataSync tasks you created.</p><p><h3>See Also:</h3>  
         * <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/ListTasks">AWS
         * API Reference</a></p>
         */
        virtual Model::ListTasksOutcome ListTasks(const Model::ListTasksRequest& request = {}) const;

        /**
         * A Callable wrapper for ListTasks that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename ListTasksRequestT = Model::ListTasksRequest>
        Model::ListTasksOutcomeCallable ListTasksCallable(const ListTasksRequestT& request = {}) const
        {
            return SubmitCallable(&DataSyncClient::ListTasks, request);
        }

        /**
         * An Async wrapper for ListTasks that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename ListTasksRequestT = Model::ListTasksRequest>
        void ListTasksAsync(const ListTasksResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr, const ListTasksRequestT& request = {}) const
        {
            return SubmitAsync(&DataSyncClient::ListTasks, request, handler, context);
        }

        /**
         * <p>Starts an DataSync transfer task. For each task, you can only run one task
         * execution at a time.</p> <p>There are several steps to a task execution. For
         * more information, see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/working-with-task-executions.html#understand-task-execution-statuses">Task
         * execution statuses</a>.</p>  <p>If you're planning to transfer data
         * to or from an Amazon S3 location, review <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-s3-location.html#create-s3-location-s3-requests">how
         * DataSync can affect your S3 request charges</a> and the <a
         * href="http://aws.amazon.com/datasync/pricing/">DataSync pricing page</a> before
         * you begin.</p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/StartTaskExecution">AWS
         * API Reference</a></p>
         */
        virtual Model::StartTaskExecutionOutcome StartTaskExecution(const Model::StartTaskExecutionRequest& request) const;

        /**
         * A Callable wrapper for StartTaskExecution that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename StartTaskExecutionRequestT = Model::StartTaskExecutionRequest>
        Model::StartTaskExecutionOutcomeCallable StartTaskExecutionCallable(const StartTaskExecutionRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::StartTaskExecution, request);
        }

        /**
         * An Async wrapper for StartTaskExecution that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename StartTaskExecutionRequestT = Model::StartTaskExecutionRequest>
        void StartTaskExecutionAsync(const StartTaskExecutionRequestT& request, const StartTaskExecutionResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::StartTaskExecution, request, handler, context);
        }

        /**
         * <p>Applies a <i>tag</i> to an Amazon Web Services resource. Tags are key-value
         * pairs that can help you manage, filter, and search for your resources.</p>
         * <p>These include DataSync resources, such as locations, tasks, and task
         * executions.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/TagResource">AWS
         * API Reference</a></p>
         */
        virtual Model::TagResourceOutcome TagResource(const Model::TagResourceRequest& request) const;

        /**
         * A Callable wrapper for TagResource that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename TagResourceRequestT = Model::TagResourceRequest>
        Model::TagResourceOutcomeCallable TagResourceCallable(const TagResourceRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::TagResource, request);
        }

        /**
         * An Async wrapper for TagResource that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename TagResourceRequestT = Model::TagResourceRequest>
        void TagResourceAsync(const TagResourceRequestT& request, const TagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::TagResource, request, handler, context);
        }

        /**
         * <p>Removes tags from an Amazon Web Services resource.</p><p><h3>See Also:</h3>  
         * <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UntagResource">AWS
         * API Reference</a></p>
         */
        virtual Model::UntagResourceOutcome UntagResource(const Model::UntagResourceRequest& request) const;

        /**
         * A Callable wrapper for UntagResource that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UntagResourceRequestT = Model::UntagResourceRequest>
        Model::UntagResourceOutcomeCallable UntagResourceCallable(const UntagResourceRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UntagResource, request);
        }

        /**
         * An Async wrapper for UntagResource that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UntagResourceRequestT = Model::UntagResourceRequest>
        void UntagResourceAsync(const UntagResourceRequestT& request, const UntagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UntagResource, request, handler, context);
        }

        /**
         * <p>Updates the name of an DataSync agent.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateAgent">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateAgentOutcome UpdateAgent(const Model::UpdateAgentRequest& request) const;

        /**
         * A Callable wrapper for UpdateAgent that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateAgentRequestT = Model::UpdateAgentRequest>
        Model::UpdateAgentOutcomeCallable UpdateAgentCallable(const UpdateAgentRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateAgent, request);
        }

        /**
         * An Async wrapper for UpdateAgent that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateAgentRequestT = Model::UpdateAgentRequest>
        void UpdateAgentAsync(const UpdateAgentRequestT& request, const UpdateAgentResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateAgent, request, handler, context);
        }

        /**
         * <p>Modifies the following configurations of the Microsoft Azure Blob Storage
         * transfer location that you're using with DataSync.</p> <p>For more information,
         * see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/creating-azure-blob-location.html">Configuring
         * DataSync transfers with Azure Blob Storage</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateLocationAzureBlob">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateLocationAzureBlobOutcome UpdateLocationAzureBlob(const Model::UpdateLocationAzureBlobRequest& request) const;

        /**
         * A Callable wrapper for UpdateLocationAzureBlob that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateLocationAzureBlobRequestT = Model::UpdateLocationAzureBlobRequest>
        Model::UpdateLocationAzureBlobOutcomeCallable UpdateLocationAzureBlobCallable(const UpdateLocationAzureBlobRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateLocationAzureBlob, request);
        }

        /**
         * An Async wrapper for UpdateLocationAzureBlob that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateLocationAzureBlobRequestT = Model::UpdateLocationAzureBlobRequest>
        void UpdateLocationAzureBlobAsync(const UpdateLocationAzureBlobRequestT& request, const UpdateLocationAzureBlobResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateLocationAzureBlob, request, handler, context);
        }

        /**
         * <p>Modifies the following configuration parameters of the Amazon EFS transfer
         * location that you're using with DataSync.</p> <p>For more information, see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-efs-location.html">Configuring
         * DataSync transfers with Amazon EFS</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateLocationEfs">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateLocationEfsOutcome UpdateLocationEfs(const Model::UpdateLocationEfsRequest& request) const;

        /**
         * A Callable wrapper for UpdateLocationEfs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateLocationEfsRequestT = Model::UpdateLocationEfsRequest>
        Model::UpdateLocationEfsOutcomeCallable UpdateLocationEfsCallable(const UpdateLocationEfsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateLocationEfs, request);
        }

        /**
         * An Async wrapper for UpdateLocationEfs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateLocationEfsRequestT = Model::UpdateLocationEfsRequest>
        void UpdateLocationEfsAsync(const UpdateLocationEfsRequestT& request, const UpdateLocationEfsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateLocationEfs, request, handler, context);
        }

        /**
         * <p>Modifies the following configuration parameters of the Amazon FSx for Lustre
         * transfer location that you're using with DataSync.</p> <p>For more information,
         * see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-lustre-location.html">Configuring
         * DataSync transfers with FSx for Lustre</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateLocationFsxLustre">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateLocationFsxLustreOutcome UpdateLocationFsxLustre(const Model::UpdateLocationFsxLustreRequest& request) const;

        /**
         * A Callable wrapper for UpdateLocationFsxLustre that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateLocationFsxLustreRequestT = Model::UpdateLocationFsxLustreRequest>
        Model::UpdateLocationFsxLustreOutcomeCallable UpdateLocationFsxLustreCallable(const UpdateLocationFsxLustreRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateLocationFsxLustre, request);
        }

        /**
         * An Async wrapper for UpdateLocationFsxLustre that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateLocationFsxLustreRequestT = Model::UpdateLocationFsxLustreRequest>
        void UpdateLocationFsxLustreAsync(const UpdateLocationFsxLustreRequestT& request, const UpdateLocationFsxLustreResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateLocationFsxLustre, request, handler, context);
        }

        /**
         * <p>Modifies the following configuration parameters of the Amazon FSx for NetApp
         * ONTAP transfer location that you're using with DataSync.</p> <p>For more
         * information, see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-ontap-location.html">Configuring
         * DataSync transfers with FSx for ONTAP</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateLocationFsxOntap">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateLocationFsxOntapOutcome UpdateLocationFsxOntap(const Model::UpdateLocationFsxOntapRequest& request) const;

        /**
         * A Callable wrapper for UpdateLocationFsxOntap that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateLocationFsxOntapRequestT = Model::UpdateLocationFsxOntapRequest>
        Model::UpdateLocationFsxOntapOutcomeCallable UpdateLocationFsxOntapCallable(const UpdateLocationFsxOntapRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateLocationFsxOntap, request);
        }

        /**
         * An Async wrapper for UpdateLocationFsxOntap that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateLocationFsxOntapRequestT = Model::UpdateLocationFsxOntapRequest>
        void UpdateLocationFsxOntapAsync(const UpdateLocationFsxOntapRequestT& request, const UpdateLocationFsxOntapResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateLocationFsxOntap, request, handler, context);
        }

        /**
         * <p>Modifies the following configuration parameters of the Amazon FSx for OpenZFS
         * transfer location that you're using with DataSync.</p> <p>For more information,
         * see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-openzfs-location.html">Configuring
         * DataSync transfers with FSx for OpenZFS</a>.</p>  <p>Request parameters
         * related to <code>SMB</code> aren't supported with the
         * <code>UpdateLocationFsxOpenZfs</code> operation.</p> <p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateLocationFsxOpenZfs">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateLocationFsxOpenZfsOutcome UpdateLocationFsxOpenZfs(const Model::UpdateLocationFsxOpenZfsRequest& request) const;

        /**
         * A Callable wrapper for UpdateLocationFsxOpenZfs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateLocationFsxOpenZfsRequestT = Model::UpdateLocationFsxOpenZfsRequest>
        Model::UpdateLocationFsxOpenZfsOutcomeCallable UpdateLocationFsxOpenZfsCallable(const UpdateLocationFsxOpenZfsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateLocationFsxOpenZfs, request);
        }

        /**
         * An Async wrapper for UpdateLocationFsxOpenZfs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateLocationFsxOpenZfsRequestT = Model::UpdateLocationFsxOpenZfsRequest>
        void UpdateLocationFsxOpenZfsAsync(const UpdateLocationFsxOpenZfsRequestT& request, const UpdateLocationFsxOpenZfsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateLocationFsxOpenZfs, request, handler, context);
        }

        /**
         * <p>Modifies the following configuration parameters of the Amazon FSx for Windows
         * File Server transfer location that you're using with DataSync.</p> <p>For more
         * information, see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-fsx-location.html">Configuring
         * DataSync transfers with FSx for Windows File Server</a>.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateLocationFsxWindows">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateLocationFsxWindowsOutcome UpdateLocationFsxWindows(const Model::UpdateLocationFsxWindowsRequest& request) const;

        /**
         * A Callable wrapper for UpdateLocationFsxWindows that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateLocationFsxWindowsRequestT = Model::UpdateLocationFsxWindowsRequest>
        Model::UpdateLocationFsxWindowsOutcomeCallable UpdateLocationFsxWindowsCallable(const UpdateLocationFsxWindowsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateLocationFsxWindows, request);
        }

        /**
         * An Async wrapper for UpdateLocationFsxWindows that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateLocationFsxWindowsRequestT = Model::UpdateLocationFsxWindowsRequest>
        void UpdateLocationFsxWindowsAsync(const UpdateLocationFsxWindowsRequestT& request, const UpdateLocationFsxWindowsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateLocationFsxWindows, request, handler, context);
        }

        /**
         * <p>Modifies the following configuration parameters of the Hadoop Distributed
         * File System (HDFS) transfer location that you're using with DataSync.</p> <p>For
         * more information, see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-hdfs-location.html">Configuring
         * DataSync transfers with an HDFS cluster</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateLocationHdfs">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateLocationHdfsOutcome UpdateLocationHdfs(const Model::UpdateLocationHdfsRequest& request) const;

        /**
         * A Callable wrapper for UpdateLocationHdfs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateLocationHdfsRequestT = Model::UpdateLocationHdfsRequest>
        Model::UpdateLocationHdfsOutcomeCallable UpdateLocationHdfsCallable(const UpdateLocationHdfsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateLocationHdfs, request);
        }

        /**
         * An Async wrapper for UpdateLocationHdfs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateLocationHdfsRequestT = Model::UpdateLocationHdfsRequest>
        void UpdateLocationHdfsAsync(const UpdateLocationHdfsRequestT& request, const UpdateLocationHdfsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateLocationHdfs, request, handler, context);
        }

        /**
         * <p>Modifies the following configuration parameters of the Network File System
         * (NFS) transfer location that you're using with DataSync.</p> <p>For more
         * information, see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-nfs-location.html">Configuring
         * transfers with an NFS file server</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateLocationNfs">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateLocationNfsOutcome UpdateLocationNfs(const Model::UpdateLocationNfsRequest& request) const;

        /**
         * A Callable wrapper for UpdateLocationNfs that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateLocationNfsRequestT = Model::UpdateLocationNfsRequest>
        Model::UpdateLocationNfsOutcomeCallable UpdateLocationNfsCallable(const UpdateLocationNfsRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateLocationNfs, request);
        }

        /**
         * An Async wrapper for UpdateLocationNfs that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateLocationNfsRequestT = Model::UpdateLocationNfsRequest>
        void UpdateLocationNfsAsync(const UpdateLocationNfsRequestT& request, const UpdateLocationNfsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateLocationNfs, request, handler, context);
        }

        /**
         * <p>Modifies the following configuration parameters of the object storage
         * transfer location that you're using with DataSync.</p> <p>For more information,
         * see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-object-location.html">Configuring
         * DataSync transfers with an object storage system</a>.</p><p><h3>See Also:</h3>  
         * <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateLocationObjectStorage">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateLocationObjectStorageOutcome UpdateLocationObjectStorage(const Model::UpdateLocationObjectStorageRequest& request) const;

        /**
         * A Callable wrapper for UpdateLocationObjectStorage that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateLocationObjectStorageRequestT = Model::UpdateLocationObjectStorageRequest>
        Model::UpdateLocationObjectStorageOutcomeCallable UpdateLocationObjectStorageCallable(const UpdateLocationObjectStorageRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateLocationObjectStorage, request);
        }

        /**
         * An Async wrapper for UpdateLocationObjectStorage that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateLocationObjectStorageRequestT = Model::UpdateLocationObjectStorageRequest>
        void UpdateLocationObjectStorageAsync(const UpdateLocationObjectStorageRequestT& request, const UpdateLocationObjectStorageResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateLocationObjectStorage, request, handler, context);
        }

        /**
         * <p>Modifies the following configuration parameters of the Amazon S3 transfer
         * location that you're using with DataSync.</p>  <p>Before you begin,
         * make sure that you read the following topics:</p> <ul> <li> <p> <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-s3-location.html#using-storage-classes">Storage
         * class considerations with Amazon S3 locations</a> </p> </li> <li> <p> <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-s3-location.html#create-s3-location-s3-requests">Evaluating
         * S3 request costs when using DataSync</a> </p> </li> </ul> <p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateLocationS3">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateLocationS3Outcome UpdateLocationS3(const Model::UpdateLocationS3Request& request) const;

        /**
         * A Callable wrapper for UpdateLocationS3 that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateLocationS3RequestT = Model::UpdateLocationS3Request>
        Model::UpdateLocationS3OutcomeCallable UpdateLocationS3Callable(const UpdateLocationS3RequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateLocationS3, request);
        }

        /**
         * An Async wrapper for UpdateLocationS3 that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateLocationS3RequestT = Model::UpdateLocationS3Request>
        void UpdateLocationS3Async(const UpdateLocationS3RequestT& request, const UpdateLocationS3ResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateLocationS3, request, handler, context);
        }

        /**
         * <p>Modifies the following configuration parameters of the Server Message Block
         * (SMB) transfer location that you're using with DataSync.</p> <p>For more
         * information, see <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/create-smb-location.html">Configuring
         * DataSync transfers with an SMB file server</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateLocationSmb">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateLocationSmbOutcome UpdateLocationSmb(const Model::UpdateLocationSmbRequest& request) const;

        /**
         * A Callable wrapper for UpdateLocationSmb that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateLocationSmbRequestT = Model::UpdateLocationSmbRequest>
        Model::UpdateLocationSmbOutcomeCallable UpdateLocationSmbCallable(const UpdateLocationSmbRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateLocationSmb, request);
        }

        /**
         * An Async wrapper for UpdateLocationSmb that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateLocationSmbRequestT = Model::UpdateLocationSmbRequest>
        void UpdateLocationSmbAsync(const UpdateLocationSmbRequestT& request, const UpdateLocationSmbResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateLocationSmb, request, handler, context);
        }

        /**
         * <p>Updates the configuration of a <i>task</i>, which defines where and how
         * DataSync transfers your data.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateTask">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateTaskOutcome UpdateTask(const Model::UpdateTaskRequest& request) const;

        /**
         * A Callable wrapper for UpdateTask that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateTaskRequestT = Model::UpdateTaskRequest>
        Model::UpdateTaskOutcomeCallable UpdateTaskCallable(const UpdateTaskRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateTask, request);
        }

        /**
         * An Async wrapper for UpdateTask that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateTaskRequestT = Model::UpdateTaskRequest>
        void UpdateTaskAsync(const UpdateTaskRequestT& request, const UpdateTaskResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateTask, request, handler, context);
        }

        /**
         * <p>Updates the configuration of a running DataSync task execution.</p> 
         * <p>Currently, the only <code>Option</code> that you can modify with
         * <code>UpdateTaskExecution</code> is <code> <a
         * href="https://docs.aws.amazon.com/datasync/latest/userguide/API_Options.html#DataSync-Type-Options-BytesPerSecond">BytesPerSecond</a>
         * </code>, which throttles bandwidth for a running or queued task execution.</p>
         * <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/datasync-2018-11-09/UpdateTaskExecution">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateTaskExecutionOutcome UpdateTaskExecution(const Model::UpdateTaskExecutionRequest& request) const;

        /**
         * A Callable wrapper for UpdateTaskExecution that returns a future to the operation so that it can be executed in parallel to other requests.
         */
        template<typename UpdateTaskExecutionRequestT = Model::UpdateTaskExecutionRequest>
        Model::UpdateTaskExecutionOutcomeCallable UpdateTaskExecutionCallable(const UpdateTaskExecutionRequestT& request) const
        {
            return SubmitCallable(&DataSyncClient::UpdateTaskExecution, request);
        }

        /**
         * An Async wrapper for UpdateTaskExecution that queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        template<typename UpdateTaskExecutionRequestT = Model::UpdateTaskExecutionRequest>
        void UpdateTaskExecutionAsync(const UpdateTaskExecutionRequestT& request, const UpdateTaskExecutionResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const
        {
            return SubmitAsync(&DataSyncClient::UpdateTaskExecution, request, handler, context);
        }


      void OverrideEndpoint(const Aws::String& endpoint);
      std::shared_ptr<DataSyncEndpointProviderBase>& accessEndpointProvider();
    private:
      friend class Aws::Client::ClientWithAsyncTemplateMethods<DataSyncClient>;
      void init(const DataSyncClientConfiguration& clientConfiguration);

      DataSyncClientConfiguration m_clientConfiguration;
      std::shared_ptr<DataSyncEndpointProviderBase> m_endpointProvider;
  };

} // namespace DataSync
} // namespace Aws
