// Copyright Steinwurf ApS 2011-2013.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing
#include <iostream>
#include <string.h>
#include <stdint.h>

#include <kodo/rlnc/full_rlnc_codes.hpp>
#include <kodo/rlnc/on_the_fly_codes.hpp>

#include <kodo/rlnc/sliding_window_encoder.hpp>
#include <kodo/rlnc/sliding_window_decoder.hpp>

#include "encoder_factory_wrapper.hpp"
#include "decoder_factory_wrapper.hpp"
#include "ckodo.h"

// Initialize the type constants
// Typdefs for the encoder/decoder type we wish to use
// also if it has trace enabled or not
typedef kodo::full_rlnc_encoder<fifi::binary> full_rlnc_encoder;
typedef kodo::full_rlnc_decoder<fifi::binary> full_rlnc_decoder;

typedef kodo::full_rlnc_encoder<fifi::binary, kodo::enable_trace>
    full_rlnc_encoder_trace;
typedef kodo::full_rlnc_decoder<fifi::binary, kodo::enable_trace>
    full_rlnc_decoder_trace;


typedef kodo::full_rlnc_encoder<fifi::binary8> full_rlnc_encoder8;
typedef kodo::full_rlnc_decoder<fifi::binary8> full_rlnc_decoder8;

typedef kodo::full_rlnc_encoder<fifi::binary8, kodo::enable_trace>
    full_rlnc_encoder_trace8;
typedef kodo::full_rlnc_decoder<fifi::binary8, kodo::enable_trace>
    full_rlnc_decoder_trace8;

typedef kodo::full_rlnc_encoder<fifi::binary16> full_rlnc_encoder16;
typedef kodo::full_rlnc_decoder<fifi::binary16> full_rlnc_decoder16;

typedef kodo::full_rlnc_encoder<fifi::binary16, kodo::enable_trace>
    full_rlnc_encoder_trace16;
typedef kodo::full_rlnc_decoder<fifi::binary16, kodo::enable_trace>
    full_rlnc_decoder_trace16;

// Typedefs for the on-the-fly coders

typedef kodo::on_the_fly_encoder<fifi::binary> on_the_fly_encoder;
typedef kodo::on_the_fly_decoder<fifi::binary> on_the_fly_decoder;

typedef kodo::on_the_fly_encoder<fifi::binary, kodo::enable_trace>
    on_the_fly_encoder_trace;
typedef kodo::on_the_fly_decoder<fifi::binary, kodo::enable_trace>
    on_the_fly_decoder_trace;


typedef kodo::on_the_fly_encoder<fifi::binary8> on_the_fly_encoder8;
typedef kodo::on_the_fly_decoder<fifi::binary8> on_the_fly_decoder8;

typedef kodo::on_the_fly_encoder<fifi::binary8, kodo::enable_trace>
    on_the_fly_encoder_trace8;
typedef kodo::on_the_fly_decoder<fifi::binary8, kodo::enable_trace>
    on_the_fly_decoder_trace8;


typedef kodo::on_the_fly_encoder<fifi::binary16> on_the_fly_encoder16;
typedef kodo::on_the_fly_decoder<fifi::binary16> on_the_fly_decoder16;

typedef kodo::on_the_fly_encoder<fifi::binary16, kodo::enable_trace>
    on_the_fly_encoder_trace16;
typedef kodo::on_the_fly_decoder<fifi::binary16, kodo::enable_trace>
    on_the_fly_decoder_trace16;


typedef kodo::sliding_window_encoder<fifi::binary> sliding_window_encoder;
typedef kodo::sliding_window_decoder<fifi::binary> sliding_window_decoder;

typedef kodo::sliding_window_encoder<fifi::binary, kodo::enable_trace>
    sliding_window_encoder_trace;
typedef kodo::sliding_window_decoder<fifi::binary, kodo::enable_trace>
    sliding_window_decoder_trace;


typedef kodo::sliding_window_encoder<fifi::binary8> sliding_window_encoder8;
typedef kodo::sliding_window_decoder<fifi::binary8> sliding_window_decoder8;

typedef kodo::sliding_window_encoder<fifi::binary8, kodo::enable_trace>
    sliding_window_encoder_trace8;
typedef kodo::sliding_window_decoder<fifi::binary8, kodo::enable_trace>
    sliding_window_decoder_trace8;

typedef kodo::sliding_window_encoder<fifi::binary16> sliding_window_encoder16;
typedef kodo::sliding_window_decoder<fifi::binary16> sliding_window_decoder16;

typedef kodo::sliding_window_encoder<fifi::binary, kodo::enable_trace>
    sliding_window_encoder_trace16;
typedef kodo::sliding_window_decoder<fifi::binary, kodo::enable_trace>
    sliding_window_decoder_trace16;


const size_t kodo_binary = typeid(fifi::binary).hash_code();
const size_t kodo_binary8 = typeid(fifi::binary8).hash_code();
const size_t kodo_binary16 = typeid(fifi::binary16).hash_code();

const size_t kodo_full_rlnc =
    typeid(full_rlnc_encoder).hash_code();

const size_t kodo_on_the_fly =
    typeid(on_the_fly_encoder).hash_code();

const size_t sliding_window =
    typeid(sliding_window).hash_code();
//

//------------------------------------------------------------------
// FACTORY API
//------------------------------------------------------------------

kodo_factory_t*
kodo_new_encoder_factory(size_t code_type, size_t field_type,
                         uint32_t max_symbols, uint32_t max_symbol_size,
                         uint32_t trace_enabled)
{
    kodo::factory *factory = 0;

    if(code_type == kodo_full_rlnc)
    {

        if(!trace_enabled)
        {
            if(field_type == kodo_binary)
            {
                factory = new kodo::encoder_factory_wrapper<
                    full_rlnc_encoder, encoder_wrapper>(
                        max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary8)
            {
                factory = new kodo::encoder_factory_wrapper<
                    full_rlnc_encoder8>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary16)
            {
                factory = new kodo::encoder_factory_wrapper<
                    full_rlnc_encoder16>(max_symbols, max_symbol_size);
            }
        }
        else
        {
            if(field_type == kodo_binary)
            {
                factory = new kodo::encoder_factory_wrapper<
                    full_rlnc_encoder_trace>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary8)
            {
                factory = new kodo::encoder_factory_wrapper<
                    full_rlnc_encoder_trace8>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary16)
            {
                factory = new kodo::encoder_factory_wrapper<
                    full_rlnc_encoder_trace16>(max_symbols, max_symbol_size);
            }

        }
        // The field type was unknown
        assert(factory);

    }
    else if(code_type == kodo_on_the_fly)
    {
        if(!trace_enabled)
        {
            if(field_type == kodo_binary)
            {
                factory = new kodo::encoder_factory_wrapper<
                    on_the_fly_encoder>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary8)
            {
                factory = new kodo::encoder_factory_wrapper<
                    on_the_fly_encoder8>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary16)
            {
                factory = new kodo::encoder_factory_wrapper<
                    on_the_fly_encoder16>(max_symbols, max_symbol_size);
            }
        }
        else
        {
            if(field_type == kodo_binary)
            {
                factory = new kodo::encoder_factory_wrapper<
                    on_the_fly_encoder_trace>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary8)
            {
                factory = new kodo::encoder_factory_wrapper<
                    on_the_fly_encoder_trace8>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary16)
            {
                factory = new kodo::encoder_factory_wrapper<
                    on_the_fly_encoder_trace16>(max_symbols, max_symbol_size);
            }
        }
        // The field type was unknown
        assert(factory);
    }
    else if (code_type == sliding_window)
    {
      if(!trace_enabled)
      {
            if(field_type == kodo_binary)
            {
                factory = new kodo::encoder_factory_wrapper<
                  sliding_window_encoder>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary8)
            {
                factory = new kodo::feedback_encoder_factory_wrapper<
                  sliding_window_encoder8>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary16)
            {
                factory = new kodo::encoder_factory_wrapper<
                    sliding_window_encoder16>(max_symbols, max_symbol_size);
            }
      }
      else
      {
            if(field_type == kodo_binary)
            {
                factory = new kodo::encoder_factory_wrapper<
                    sliding_window_encoder_trace>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary8)
            {
                factory = new kodo::encoder_factory_wrapper<
                    sliding_window_encoder_trace8>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary16)
            {
                factory = new kodo::encoder_factory_wrapper<
                    sliding_window_encoder_trace16>(max_symbols, max_symbol_size);
            }
      }
    }

    // The code type was unknown
    assert(factory);

    return (kodo_factory_t*)factory;
}


kodo_factory_t*
kodo_new_decoder_factory(size_t code_type, size_t field_type,
                         uint32_t max_symbols, uint32_t max_symbol_size,
                         uint32_t trace_enabled)
{
    kodo::factory *factory = 0;
    if(code_type == kodo_full_rlnc)
    {
        if(!trace_enabled)
        {
            if(field_type == kodo_binary)
            {
                factory = new kodo::decoder_factory_wrapper<
                    full_rlnc_decoder>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary8)
            {
                factory = new kodo::decoder_factory_wrapper<
                    full_rlnc_decoder8>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary16)
            {
                factory = new kodo::decoder_factory_wrapper<
                    full_rlnc_decoder16>(max_symbols, max_symbol_size);
            }
        }
        else
        {
            if(field_type == kodo_binary)
            {
                factory = new kodo::decoder_factory_wrapper<
                    full_rlnc_decoder_trace>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary8)
            {
                factory = new kodo::decoder_factory_wrapper<
                    full_rlnc_decoder_trace8>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary16)
            {
                factory = new kodo::decoder_factory_wrapper<
                    full_rlnc_decoder_trace16>(max_symbols, max_symbol_size);
            }
       }

        // The field type was unknown
        assert(factory);

    }
    else if(code_type == kodo_on_the_fly)
    {
        if(!trace_enabled)
        {
            if(field_type == kodo_binary)
            {
                factory = new kodo::decoder_factory_wrapper<
                    on_the_fly_decoder>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary8)
            {
                factory = new kodo::decoder_factory_wrapper<
                on_the_fly_decoder8>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary16)
            {
                factory = new kodo::decoder_factory_wrapper<
                    on_the_fly_decoder16>(max_symbols, max_symbol_size);
            }
        }
        else
        {
            if(field_type == kodo_binary)
            {
                factory = new kodo::decoder_factory_wrapper<
                    on_the_fly_decoder_trace>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary8)
            {
                factory = new kodo::decoder_factory_wrapper<
                on_the_fly_decoder_trace8>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary16)
            {
                factory = new kodo::decoder_factory_wrapper<
                    on_the_fly_decoder_trace16>(max_symbols, max_symbol_size);
            }
        }

            // The field type was unknown
            assert(factory);

    }
    else if(code_type == sliding_window)
    {
        if(!trace_enabled)
        {
            if(field_type == kodo_binary)
            {
                factory = new kodo::decoder_factory_wrapper<
                    sliding_window_decoder>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary8)
            {
                factory = new kodo::decoder_factory_wrapper<
                sliding_window_decoder8>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary16)
            {
                factory = new kodo::decoder_factory_wrapper<
                    sliding_window_decoder16>(max_symbols, max_symbol_size);
            }
        }
        else
        {
            if(field_type == kodo_binary)
            {
                factory = new kodo::decoder_factory_wrapper<
                    sliding_window_decoder_trace>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary8)
            {
                factory = new kodo::decoder_factory_wrapper<
                sliding_window_decoder_trace8>(max_symbols, max_symbol_size);
            }
            else if(field_type == kodo_binary16)
            {
                factory = new kodo::decoder_factory_wrapper<
                    sliding_window_decoder_trace16>(max_symbols, max_symbol_size);
            }
        }

            // The field type was unknown
            assert(factory);
    }

    // The code type was unknown
    assert(factory);

    return (kodo_factory_t*)factory;
}

void kodo_delete_encoder_factory(kodo_factory_t* factory)
{
    assert(factory);

    kodo::factory* the_factory = (kodo::factory*) factory;
    delete the_factory;
}

void kodo_delete_decoder_factory(kodo_factory_t* factory)
{
    assert(factory);

    kodo::factory* the_factory = (kodo::factory*) factory;
    delete the_factory;
}


uint32_t kodo_factory_max_symbols(kodo_factory_t* factory)
{
    assert(factory);

    kodo::factory* the_factory = (kodo::factory*) factory;
    return the_factory->max_symbols();
}

uint32_t kodo_factory_max_symbol_size(kodo_factory_t* factory)
{
    assert(factory);

    kodo::factory* the_factory = (kodo::factory*) factory;
    return the_factory->max_symbol_size();
}

uint32_t kodo_factory_max_block_size(kodo_factory_t* factory)
{
    assert(factory);

    kodo::factory* the_factory = (kodo::factory*) factory;
    return the_factory->max_block_size();
}

uint32_t kodo_factory_max_payload_size(kodo_factory_t* factory)
{
    assert(factory);

    kodo::factory* the_factory = (kodo::factory*) factory;
    return the_factory->max_payload_size();
}

void kodo_factory_set_symbols(kodo_factory_t* factory, uint32_t symbols)
{
    assert(factory);

    kodo::factory* the_factory = (kodo::factory*) factory;
    the_factory->set_symbols(symbols);
}

void kodo_factory_set_symbol_size(kodo_factory_t* factory,
                                  uint32_t symbol_size)
{
    assert(factory);

    kodo::factory* the_factory = (kodo::factory*) factory;
    the_factory->set_symbol_size(symbol_size);
}


kodo_coder_t* kodo_factory_new_encoder(kodo_factory_t* factory)
{
    assert(factory);

    kodo::factory* the_factory = (kodo::factory*) factory;
    void* encoder = the_factory->build();
    return (kodo_coder_t*) encoder;
}

kodo_coder_t* kodo_factory_new_decoder(kodo_factory_t* factory)
{
    assert(factory);

    kodo::factory* the_factory = (kodo::factory*) factory;
    void* decoder = the_factory->build();
    return (kodo_coder_t*) decoder;
}

void kodo_delete_encoder(kodo_coder_t* encoder)
{
    assert(encoder);

    kodo::encoder* the_encoder = (kodo::encoder*) encoder;
    delete the_encoder;
}

void kodo_delete_decoder(kodo_coder_t* decoder)
{
    assert(decoder);

    kodo::decoder* the_decoder = (kodo::decoder*) decoder;
    delete the_decoder;
}

//------------------------------------------------------------------
// PAYLOAD API
//------------------------------------------------------------------

uint32_t kodo_payload_size(kodo_coder_t* coder)
{
    assert(coder);

    kodo::coder* the_coder = (kodo::coder*) coder;
    return the_coder->payload_size();
}

void kodo_decode(kodo_coder_t* decoder, uint8_t* payload)
{
    assert(decoder);

    kodo::decoder* the_decoder = (kodo::decoder*) decoder;
    the_decoder->decode(payload);
}

uint32_t kodo_recode(kodo_coder_t* decoder, uint8_t* payload)
{
    assert(decoder);

    kodo::decoder* the_decoder = (kodo::decoder*) decoder;
    return the_decoder->recode(payload);
}

uint32_t kodo_encode(kodo_coder_t* encoder, uint8_t* payload)
{
    assert(encoder);

    kodo::encoder* the_encoder = (kodo::encoder*) encoder;
    return the_encoder->encode(payload);
}

//------------------------------------------------------------------
// SYMBOL STORAGE API
//------------------------------------------------------------------

uint32_t kodo_block_size(kodo_coder_t* coder)
{
    assert(coder);

    kodo::coder* the_coder = (kodo::coder*) coder;
    return the_coder->block_size();
}


void kodo_set_symbols(kodo_coder_t* encoder, const uint8_t* data,
                      uint32_t size)
{
    assert(encoder);

    kodo::encoder* the_encoder = (kodo::encoder*) encoder;
    the_encoder->set_symbols(data, size);
}

void kodo_set_symbol(kodo_coder_t* encoder, uint32_t index,
                     const uint8_t* data, uint32_t size)
{
    assert(encoder);

    kodo::encoder* the_encoder = (kodo::encoder*) encoder;
    the_encoder->set_symbol(index, data, size);
}

void kodo_copy_symbols(kodo_coder_t* decoder, uint8_t* data, uint32_t size)
{
    assert(decoder);

    kodo::decoder* the_decoder = (kodo::decoder*) decoder;
    the_decoder->copy_symbols(data, size);
}

void kodo_copy_symbol(kodo_coder_t* decoder, uint32_t index,
                      uint8_t* data, uint32_t size)
{
    assert(decoder);

    kodo::decoder* the_decoder = (kodo::decoder*) decoder;
    the_decoder->copy_symbol(index, data, size);

}


uint32_t kodo_symbol_size(kodo_coder_t* coder)
{
    assert(coder);

    kodo::coder* the_coder = (kodo::coder*) coder;
    return the_coder->symbol_size();
}

uint32_t kodo_symbols(kodo_coder_t* coder)
{
    assert(coder);

    kodo::coder* the_coder = (kodo::coder*) coder;
    return the_coder->symbols();
}


//------------------------------------------------------------------
// CODEC API
//------------------------------------------------------------------

uint8_t kodo_is_complete(kodo_coder_t* decoder)
{
    assert(decoder);

    kodo::decoder* the_decoder = (kodo::decoder*) decoder;
    return (uint8_t)the_decoder->is_complete();
}

uint8_t kodo_is_partial_complete(kodo_coder_t* decoder)
{
    assert(decoder);

    kodo::decoder* the_decoder = (kodo::decoder*) decoder;
    return (uint8_t)the_decoder->is_partial_complete();

}

uint8_t kodo_feedback_size(kodo_coder_t* coder)
{
    kodo::coder* the_coder = (kodo::coder*) coder;
    //    return (uint8_t)the_coder->feedback_size();
    return -1;
}

uint32_t kodo_rank(kodo_coder_t* decoder)
{
    assert(decoder);

    kodo::decoder* the_decoder = (kodo::decoder*) decoder;
    return the_decoder->rank();
}

uint8_t kodo_symbol_pivot(kodo_coder_t* coder, uint32_t index)
{
    assert(coder);

    kodo::coder* the_coder = (kodo::coder*) coder;
    return the_coder->symbol_pivot(index);
}

uint8_t kodo_is_symbol_uncoded(kodo_coder_t* decoder, uint32_t index)
{
    assert(decoder);

    kodo::decoder* the_decoder = (kodo::decoder*) decoder;
    return the_decoder->is_symbol_uncoded(index);
}

uint32_t kodo_symbols_uncoded(kodo_coder_t* decoder)
{
    kodo::decoder* the_decoder = (kodo::decoder*) decoder;
    return the_decoder->symbols_uncoded();
}

uint32_t kodo_symbols_seen(kodo_coder_t* decoder)
{
  kodo::decoder* the_decoder = (kodo::decoder*) decoder;
  return the_decoder->symbols_seen();
}

//------------------------------------------------------------------
// GENERIC API
//------------------------------------------------------------------

uint8_t kodo_has_partial_decoding_tracker(kodo_coder_t* decoder)
{
    assert(decoder);

    kodo::decoder* the_decoder = (kodo::decoder*) decoder;
    return (uint8_t)the_decoder->has_partial_decoding_tracker();
}

uint8_t kodo_is_systematic_on(kodo_coder_t* encoder)
{
    assert(encoder);

    kodo::encoder* the_encoder = (kodo::encoder*) encoder;
    return (uint8_t)the_encoder->is_systematic_on();
}

void kodo_set_systematic_on(kodo_coder_t* encoder)
{
    assert(encoder);

    kodo::encoder* the_encoder = (kodo::encoder*) encoder;
    the_encoder->set_systematic_on();
}

void kodo_set_systematic_off(kodo_coder_t* encoder)
{
    assert(encoder);

    kodo::encoder* the_encoder = (kodo::encoder*) encoder;
    the_encoder->set_systematic_off();
}

//KODO 17 Trace methods
//------------------------------------------------------------------
// TRACE API
//------------------------------------------------------------------
void kodo_trace_filter(kodo_coder_t* coder, kodo_filter_function_t filter)
{
    kodo::coder* the_coder = (kodo::coder*) coder;
    the_coder->trace(filter);
}

void kodo_trace(kodo_coder_t* coder)
{
    kodo::coder* the_coder = (kodo::coder*) coder;
    //SEND NULL TO Trace
    the_coder->trace(NULL);
}

uint8_t kodo_has_trace(kodo_coder_t* coder)
{
    assert(coder);
    kodo::coder* the_coder = (kodo::coder*) coder;
    return (uint8_t)the_coder->has_trace();
}


