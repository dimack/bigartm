// Copyright 2014, Additive Regularization of Topic Models.
// This file defines public API methods of BigARTM library.
// All methods must be inside "extern "C"" scope. All complex data structures should be passed in
// as Google Protobuf Messages, defined in messages.proto.

#ifndef SRC_ARTM_C_INTERFACE_H_
#define SRC_ARTM_C_INTERFACE_H_

#include <cstddef>

#if defined(WIN32)
  #ifdef artm_EXPORTS
    #define DLL_PUBLIC __declspec(dllexport)
  #else
    #define DLL_PUBLIC __declspec(dllimport)
  #endif
#else
  #define DLL_PUBLIC
#endif

extern "C" {
  DLL_PUBLIC int ArtmDuplicateMasterComponent(int master_id, size_t length, const char* duplicate_master_args);
  DLL_PUBLIC int ArtmCreateMasterModel(size_t length, const char* master_model_config);
  DLL_PUBLIC int ArtmReconfigureMasterModel(int master_id, size_t length, const char* master_model_config);
  DLL_PUBLIC int ArtmDisposeMasterComponent(int master_id);

  DLL_PUBLIC int ArtmDisposeModel(int master_id, const char* model_name);

  DLL_PUBLIC int ArtmClearThetaCache(int master_id, size_t length, const char* clear_theta_cache_args);
  DLL_PUBLIC int ArtmClearScoreCache(int master_id, size_t length, const char* clear_score_cache_args);
  DLL_PUBLIC int ArtmClearScoreArrayCache(int master_id, size_t length, const char* clear_score_array_cache_args);

  DLL_PUBLIC int ArtmCreateRegularizer(int master_id, size_t length, const char* regularizer_config);
  DLL_PUBLIC int ArtmReconfigureRegularizer(int master_id, size_t length, const char* regularizer_config);
  DLL_PUBLIC int ArtmDisposeRegularizer(int master_id, const char* regularizer_name);

  DLL_PUBLIC int ArtmGatherDictionary(int master_id, size_t length, const char* gather_dictionary_args);
  DLL_PUBLIC int ArtmFilterDictionary(int master_id, size_t length, const char* filter_dictionary_args);
  DLL_PUBLIC int ArtmCreateDictionary(int master_id, size_t length, const char* dictionary_data);
  DLL_PUBLIC int ArtmCreateDictionaryNamed(int master_id, size_t length, const char* dictionary_data, const char* name);
  DLL_PUBLIC size_t ArtmRequestDictionary(int master_id, size_t length, const char* request_dictionary_args);
  DLL_PUBLIC int ArtmDisposeDictionary(int master_id, const char* dictionary_name);

  DLL_PUBLIC int ArtmImportDictionary(int master_id, size_t length, const char* import_dictionary_args);
  DLL_PUBLIC int ArtmExportDictionary(int master_id, size_t length, const char* export_dictionary_args);
  DLL_PUBLIC size_t ArtmParseCollection(size_t length, const char* collection_parser_config);

  DLL_PUBLIC int ArtmImportBatches(int master_id, size_t length, const char* import_batches_args);
  DLL_PUBLIC int ArtmDisposeBatch(int master_id, const char* batch_name);

  DLL_PUBLIC int ArtmOverwriteTopicModel(int master_id, size_t length, const char* topic_model);
  DLL_PUBLIC int ArtmOverwriteTopicModelNamed(int master_id, size_t length, const char* topic_model, const char* name);
  DLL_PUBLIC int ArtmInitializeModel(int master_id, size_t length, const char* init_model_args);
  DLL_PUBLIC int ArtmExportModel(int master_id, size_t length, const char* export_model_args);
  DLL_PUBLIC int ArtmImportModel(int master_id, size_t length, const char* import_model_args);
  DLL_PUBLIC int ArtmAttachModel(int master_id, size_t length, const char* attach_model_args,
                                 int address_length, char* address);

  DLL_PUBLIC size_t ArtmRequestProcessBatches(int master_id, size_t length, const char* process_batches_args);
  DLL_PUBLIC size_t ArtmRequestProcessBatchesExternal(int master_id, size_t length, const char* process_batches_args);
  DLL_PUBLIC int ArtmAsyncProcessBatches(int master_id, size_t length, const char* process_batches_args);
  DLL_PUBLIC int ArtmMergeModel(int master_id, size_t length, const char* merge_model_args);
  DLL_PUBLIC int ArtmRegularizeModel(int master_id, size_t length, const char* regularize_model_args);
  DLL_PUBLIC int ArtmNormalizeModel(int master_id, size_t length, const char* normalize_model_args);

  DLL_PUBLIC int ArtmFitOfflineMasterModel(int master_id, size_t length, const char* fit_offline_master_model_args);
  DLL_PUBLIC int ArtmFitOnlineMasterModel(int master_id, size_t length, const char* fit_online_master_model_args);
  DLL_PUBLIC size_t ArtmRequestTransformMasterModel(int master_id, size_t length, const char* transform_master_model_args);
  DLL_PUBLIC size_t ArtmRequestTransformMasterModelExternal(int master_id, size_t length,
                                                         const char* transform_master_model_args);

  DLL_PUBLIC size_t ArtmRequestMasterModelConfig(int master_id);

  DLL_PUBLIC size_t ArtmRequestThetaMatrix(int master_id, size_t length, const char* get_theta_args);
  DLL_PUBLIC size_t ArtmRequestThetaMatrixExternal(int master_id, size_t length, const char* get_theta_args);
  DLL_PUBLIC size_t ArtmRequestTopicModel(int master_id, size_t length, const char* get_model_args);
  DLL_PUBLIC size_t ArtmRequestTopicModelExternal(int master_id, size_t length, const char* get_model_args);
  DLL_PUBLIC size_t ArtmRequestScore(int master_id, size_t length, const char* get_score_args);
  DLL_PUBLIC size_t ArtmRequestScoreArray(int master_id, size_t length, const char* get_score_args);
  DLL_PUBLIC size_t ArtmRequestMasterComponentInfo(int master_id, size_t length, const char* get_master_info_args);
  DLL_PUBLIC size_t ArtmRequestLoadBatch(const char* filename);
  DLL_PUBLIC int ArtmCopyRequestedMessage(size_t length, char* address);
  DLL_PUBLIC int ArtmCopyRequestedObject(size_t length, char* address);

  DLL_PUBLIC int ArtmAwaitOperation(int operation_id, size_t length, const char* await_operation_args);

  DLL_PUBLIC int ArtmSaveBatch(const char* disk_path, size_t length, const char* batch);
  DLL_PUBLIC const char* ArtmGetLastErrorMessage();
  DLL_PUBLIC const char* ArtmGetVersion();
  DLL_PUBLIC int ArtmConfigureLogging(size_t length, const char* configure_logging_args);

  DLL_PUBLIC int ArtmSetProtobufMessageFormatToJson();
  DLL_PUBLIC int ArtmSetProtobufMessageFormatToBinary();
  DLL_PUBLIC int ArtmProtobufMessageFormatIsJson();
}

#endif  // SRC_ARTM_C_INTERFACE_H_
